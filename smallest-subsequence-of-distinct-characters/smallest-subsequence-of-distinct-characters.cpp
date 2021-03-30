class Solution {
public:
    string smallestSubsequence(string s) {
        string res = "";
        int last[26] = {},seen[26]={};
        int len = s.length();
        for(int i = 0;i<len;i++)
        {
            last[s[i]-'a'] = i;
        }
        for(int i = 0;i<len;i++)
        {
            if(seen[s[i]-'a']++)
                continue;
            else
            {
                while(!res.empty() && res.back()>s[i] && i<last[res.back()-'a'])
                {
                    seen[res.back()-'a']=0;
                    res.pop_back();
                }
            }
            res.push_back(s[i]);
        }
        return res;
    }
};