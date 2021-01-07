class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        if(len==1 || len==0)
            return nums;
        sort(nums.begin(),nums.end());
        vector<int> dp(len,1);
        int max_ele = INT_MIN;
        for(int i = 1;i<len;i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                   if(dp[j]+1 > dp[i])
                       dp[i] = dp[j] + 1;
                }
            }
            max_ele = max(max_ele,dp[i]);
        }
        vector<int> ans;
        int prev = 0;
        for(int i = len-1;i>=0;i--)
        {
            if(dp[i]==max_ele && prev%nums[i]==0)
            {
                ans.push_back(nums[i]);
                max_ele--;
                prev = ans.back();
            }
        }
        
        return ans;
    }
};
