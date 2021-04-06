class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& a) {
        if(a.empty())
            return 0;
        sort(a.begin(),a.end());
        vector<int> dp(a.size(),1);
        for(int i = 0;i<a.size();i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(a[j][1]<a[i][1] && a[j][0] < a[i][0])
                      dp[i] = max(dp[i],dp[j]+1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};