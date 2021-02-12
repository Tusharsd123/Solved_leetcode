class Solution {
public:
   int solve(vector<vector<int>>& events, int n, int pos, int k,vector<vector<int>> &dp)
{
        int i;
        
        if(pos >= n || k == 0)
            return 0;
        if(dp[pos][k]!=-1)
               return dp[pos][k];
        for(i = pos + 1; i < n; i++)
            if(events[i][0] > events[pos][1])
                break;
        
       return dp[pos][k] = max(solve(events, n, pos+1, k,dp), events[pos][2] + solve(events, n, i, k-1,dp));
    }
    
    int maxValue(vector<vector<int>>& events, int k) 
    {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(events, n, 0, k,dp);
    }
};