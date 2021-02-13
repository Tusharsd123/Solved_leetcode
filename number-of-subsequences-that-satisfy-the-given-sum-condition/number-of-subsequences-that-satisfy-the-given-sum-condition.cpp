class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
           int n = nums.size();
         int res = 0;
        int mod = 1e9+7;
        sort(nums.begin(),nums.end());
        vector<int> pow(nums.size());
        pow[0] = 1;
        for(int i = 1;i<pow.size();i++)
              pow[i] = (pow[i-1]*2)%mod;
    for(int start = 0;start < n;start++)
    {
        int l = start, r = n-1;
        int mid;
        int end = -1;
        while(l<=r)
        {
            mid = l + (r-l)/2;
            if(nums[start]+nums[mid]<=target)
            {
                l = mid + 1;
                end = mid;
            }
            else
                r = mid - 1;
        }
        
       
        if(end==-1)
             break;
        res = (res + pow[end-start])%mod;
       }
        return res;
    }
};