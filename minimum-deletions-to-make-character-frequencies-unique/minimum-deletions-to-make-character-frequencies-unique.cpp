class Solution {
public:
    int minDeletions(string s) {
         int n = s.length();
         int cnt[26] = {};
         int res = 0;
         unordered_set<int> st;
         for(char ch : s)
             cnt[ch-'a']++;
        for(int i = 0;i<26;i++)
        {
            int freq = cnt[i];
            while(freq>0 && st.find(freq)!=st.end())
            {
                freq--;
                res++;
            }
            st.insert(freq);
        }
        return res;
    }
};


