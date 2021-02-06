class Solution {
public:
    int x[8] = {2,-2,1,-1,-1,1,-2,2};
    int y[8] = {1,-1,2,-2,2,-2,1,-1};
   double dp[26][26][101];
double find(int n,int i,int j,int k)
{
    if(i<0 || i>=n || j<0 || j>=n)
       return 0;
    if(k==0)
       return 1;
    if(dp[i][j][k]!=0)
        return dp[i][j][k]; 
    double cost;
    for(int c = 0;c<8;c++)
              cost += 0.125*(find(n,i+x[c],j+y[c],k-1));
    
    dp[i][j][k] = cost;
    return cost;
}
    double knightProbability(int N, int K, int r, int c) {
          memset(dp,0,sizeof(dp));
          return find(N,r,c,K);
    }
};