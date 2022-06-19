
class Solution {
public:
    int dp[1001][1001];
    
    int f (int i,int j,int curr,string &s,int k)
    {
        if(i<=0)
            return 0;
        if(curr>k)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i-1]=='0')
        {
            return dp[i][j] = 1 + f(i-1,j+1,curr,s,k);
        }
        else if(s[i-1]=='1' && curr+pow(2,j)<=k)
        {
            return dp[i][j] = max(1+f(i-1,j+1,curr+pow(2,j),s,k),f(i-1,j,curr,s,k));
        }
        else
            return dp[i][j] = f(i-1,j,curr,s,k);
    }
    
    
    int longestSubsequence(string s, int k) {
        int n = s.length();
        if(n==1)
        {
            if(k>=1) return 1;
            else
                return 0;
        }
        memset(dp,-1,sizeof(dp));
        return f(n,0,0,s,k);
    }
};


/*

general greedy solution

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int len = s.length();
        int val=0, pow=1 , cnt=0;
        for(int i = len-1; i>=0 && val+pow<=k; i--)
        {
            if(s[i]=='1')
            {
                cnt++;
                val += pow;
            }
            pow <<= 1;
        }
        
        return count(s.begin(),s.end(),'0') + cnt;
    }
};
*/