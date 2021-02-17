class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> p(s.length());
        for(int i = 1;i<n;i++)
        {
            int j = p[i-1];
            while(j>0 && s[i]!=s[j])
                 j = p[j-1];
            if(s[i]==s[j])
                j++;
            p[i] = j;
        }
        return s.substr(0,p[p.size()-1]);
    }
};