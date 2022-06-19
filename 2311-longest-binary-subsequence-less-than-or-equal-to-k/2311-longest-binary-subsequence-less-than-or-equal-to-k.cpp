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