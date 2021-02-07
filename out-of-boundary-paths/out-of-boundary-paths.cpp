class Solution {
public:
    int mod = pow(10,9)+7;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    int dp[51][51][51];
    int solve(int i,int j,int m,int n,int N)
    {
        if(i<0 || j<0 || i>=m || j>=n) //one path is found
            return 1;
        if(N<=0)
            return 0;
        if(dp[i][j][N]!=-1)
             return dp[i][j][N];
        int total_paths = 0;
        for(int k = 0;k<4;k++)
        {
            total_paths += solve(i+dx[k],j+dy[k],m,n,N-1)%mod;
            total_paths = total_paths%mod;
        }
        dp[i][j][N] = total_paths%mod;
        return dp[i][j][N];
    }
    int findPaths(int m, int n, int N, int i, int j) {
        memset(dp,-1,sizeof(dp));
        return solve(i,j,m,n,N);
    }
};