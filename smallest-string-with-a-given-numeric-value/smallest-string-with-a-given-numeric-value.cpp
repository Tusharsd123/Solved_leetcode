class Solution {
public:
    string getSmallestString(int n, int k) {
          int i = 26;
          string ans = "";
          int len = n;
          while(i && len)
          {
              if(k-i>=(len-1))
              {
                  ans += (char)(i-1+'a');
                  k -= i;
                  len--;
              }
              else
                  i--;
              if(len==k)
              {
                  while(len)
                  {
                      ans += 'a';
                      len--;
                  }
              }
              
          }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};