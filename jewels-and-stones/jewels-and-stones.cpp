class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> mp;
        int cnt=0;
        for(char ch : jewels)
        {
            mp.insert(ch);
        }
        for(char c : stones)
        {
            if(mp.find(c)!=mp.end())
                cnt++;
        }
        return cnt;
    }
};