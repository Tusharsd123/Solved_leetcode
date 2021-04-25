class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a,b;
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]!='#')
                a += s[i];
            else
            {
                if(!a.empty())
                    a.pop_back();
                continue;
            }
        }
        for(int i = 0;i<t.length();i++)
        {
            if(t[i]!='#')
                b += t[i];
            else
            {
                if(!b.empty())
                   b.pop_back();
                continue;
            }
        }
        return (a==b);
    }
};