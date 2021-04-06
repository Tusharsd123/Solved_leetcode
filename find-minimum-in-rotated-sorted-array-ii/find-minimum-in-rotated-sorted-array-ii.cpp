//[4 5 6 7 0 1 4]

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = nums.size()-1;
        int mid;
        while(l<r)
        {
            mid = l + (r-l)/2;
            if(nums[mid]<nums[r])
                r = mid;
            else if(nums[mid]>nums[r])
                l = mid + 1;
            else
                r--;
        }
        return nums[l];
    }
};