class Solution {
public:
    //two ways 1. Binary Search 2. DP
    
    bool is_valid(int target,vector<int> &nums,int m)
    {
        int count=1;
        int sum = 0;
        for(auto x : nums)
        {
            sum += x;
            if(sum > target)
            {
                sum = x;
                count++;
                if(count>m)
                    return false;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int len = nums.size();
        int sum = 0,max_n = INT_MIN;
        for(auto x : nums)
        {
            sum += x;
            max_n = max(max_n,x);
        }
        int l = max_n;
        int r = sum;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(is_valid(mid,nums,m))
                r = mid-1;
            else
                l = mid + 1;
        }
        return l;
    }
};