class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1);
        for(int i = 1;i<=n;i++)
        {
            int curr_max = 0,ans = 0;
            for(int K = 1;K<=k && i-K >= 0 ; K++)
            {
                curr_max = max(curr_max,arr[i-K]);
                ans = max(ans,curr_max*K+dp[i-K]);
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};
