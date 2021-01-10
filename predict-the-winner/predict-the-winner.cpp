class Solution {
public:
    int memo[21][21];
    int dp_util(vector<int>&nums,int i,int j,int sum)
    {
        if(j==i+1)
            return max(nums[i],nums[j]);
        else if(memo[i][j]!=-1)
            return memo[i][j];
        memo[i][j] = max((sum-dp_util(nums,i+1,j,sum-nums[i])),(sum-dp_util(nums,i,j-1,sum-nums[j])));
        return memo[i][j];
        }
    bool PredictTheWinner(vector<int>& nums) {
        if(nums.size()==1 || nums.size()==2)
            return true;
        int sum =0;
        sum = accumulate(nums.begin(),nums.end(),sum);
        memset(memo,-1,sizeof(memo));
        int x = dp_util(nums,0,nums.size()-1,sum);
        if(sum - x <= x)
            return true;
        else
            return false;
    }
};
