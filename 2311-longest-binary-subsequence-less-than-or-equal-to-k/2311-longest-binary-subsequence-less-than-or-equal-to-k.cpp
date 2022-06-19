
class Solution {
public:
   int dp[1001][1001];
int solve(int i,int j,int curr,int k,string &s)
{
if(i<=0)return 0;
if(curr>k)return 0;
if(dp[i][j]!=-1)return dp[i][j];

    //If curr char is '0' then we must include this  to increase the  length of subsequence
     if(s[i-1]=='0')
    {
        return dp[i][j]=1+solve(i-1,j+1,curr,k,s);
    }
    
	//If curr char is '1 then we can include it or exclude it if and only if our curr sum<=k 
    else if(s[i-1]=='1' && curr+pow(2,j)<=k)
    {
        return dp[i][j]=max(1+solve(i-1,j+1,curr+pow(2,j),k,s),solve(i-1,j,curr,k,s));
    }
    
    
    else
        return dp[i][j]=solve(i-1,j,curr,k,s);
}
int longestSubsequence(string s, int k) {
    int n=s.size();
    
    if(n==1)
    {
        if(k>=1)return 1;
        
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    
    
    return solve(n,0,0,k,s);
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