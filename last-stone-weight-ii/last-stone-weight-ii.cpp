class Solution {
public:
    int dp_util(vector<int>&stones,int i,int given_sum,int total_sum,vector<vector<int>> &dp)
    {
       if(i==0)
           return dp[i][given_sum] =  abs((total_sum-given_sum)-given_sum);
       else if(dp[i][given_sum]!=-1) 
           return dp[i][given_sum];
       else 
           return dp[i][given_sum] = min(dp_util(stones,i-1,given_sum+stones[i-1],total_sum,dp),dp_util(stones,i-1,given_sum,total_sum,dp));
    }
    int lastStoneWeightII(vector<int>& stones) {
        int len = stones.size();
        int sum = 0;
        for(int i = 0;i<len;i++)
        {
            sum += stones[i];
        }
        vector<vector<int>> dp(len+1,vector<int>(sum+1,-1));
        return dp_util(stones,len,0,sum,dp);
    }
};
