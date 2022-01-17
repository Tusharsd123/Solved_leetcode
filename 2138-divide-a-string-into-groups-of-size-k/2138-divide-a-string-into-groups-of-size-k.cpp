class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int len = s.length();
        vector<string> ans;
        int x = 0;
        if(len%k!=0)
            x = k-len%k;
        while(x--)
           s+=fill;
        for(int i =0;i<len;i+=k)
           ans.push_back(s.substr(i,k));
        return ans;
    }
};