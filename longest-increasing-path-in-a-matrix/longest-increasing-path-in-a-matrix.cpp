class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};
    int dfs(vector<vector<int>> &matrix,vector<vector<int>>&dp,int i,int j,int n,int m)
    {
        if(dp[i][j]!=0)
            return dp[i][j];
        int mx = 1;
        for(int k = 0;k<4;k++)
        {
            int a = i + x[k];
            int b = j + y[k];
            if(a<0 || b<0 || a>=n || b>=m || matrix[a][b] <= matrix[i][j])
                  continue;
            int len = 1 + dfs(matrix,dp,a,b,n,m);
            mx = max(mx,len);
        }
        dp[i][j] = mx;
        return mx;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int mx = 1;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                int len = dfs(matrix,dp,i,j,n,m);
                mx = max(mx,len);
            }
        }
        return mx;
    }
};