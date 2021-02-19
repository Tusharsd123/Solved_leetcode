class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        queue<char> q;
        int len = s.length();
        string ans = "";
        for(int i = 0;i<len;i++)
        {
            if(s[i]=='(' || isalpha(s[i]))
                st.push(s[i]);
            if(s[i]==')')
            {
                while(!st.empty() && st.top()!='(')
                {
                    char c = st.top();
                    st.pop();
                    q.push(c);
                }
                st.pop();
                while(!q.empty())
                {
                    char x = q.front();
                    q.pop();
                    st.push(x);
                }
            }
        }
        while(!st.empty())
        {
            char ch = st.top();
            st.pop();
            ans += ch;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//(ed(et(oc))el
//(ed(et(co))el)
//(ed(octe)le)
//(edetcoel)