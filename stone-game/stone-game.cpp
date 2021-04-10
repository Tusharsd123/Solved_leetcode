class Solution {
public:
    int dp[1005][1005];
    
    int solve(int l,int r,vector<int> &piles)
    {
        if(l==r-1)
            return max(piles[l],piles[r]);
        if(dp[l][r]!=-1)
            return dp[l][r];
        int left = piles[l] + min(solve(l+2,r,piles),solve(l+1,r-1,piles));
        int right = piles[r] + min(solve(l+1,r-1,piles),solve(l,r-2,piles));
        
        return dp[l][r] = max(left,right);
    }
    
    bool stoneGame(vector<int>& piles) {
        int len = piles.size();
        int l = 0;
        int r = piles.size()-1;
        memset(dp,-1,sizeof(dp));
        int alex = solve(l,r,piles);
        int sum=0;
        for(int i = 0;i<len;i++)
            sum += piles[i];
        return alex>(sum-alex);
    }
};