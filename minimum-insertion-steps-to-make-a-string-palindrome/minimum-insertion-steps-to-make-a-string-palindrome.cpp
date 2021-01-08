class Solution {
public:
    vector<vector<int>> memo;
    int dp(string &s , int i , int j)
    {
        if(i>=j)
            return 0;
        if(memo[i][j]!=-1)
            return memo[i][j];
        if(s[i]==s[j])
        {
            memo[i][j] = dp(s,i+1,j-1);
            return memo[i][j];
        }
        else
        {
            memo[i][j] = 1 + min(dp(s,i+1,j),dp(s,i,j-1));
            return memo[i][j];
        }
    }
    int minInsertions(string s) {
        memo.resize(s.length(),vector<int>(s.length(),-1));
        return dp(s,0,s.length()-1);
    }
};
