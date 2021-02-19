class Solution {
public:
    int minFlips(string s) {
        int len = s.length();
        char status = '0';
        int cnt=0;
        for(int i = 0;i<len;i++)
        {
            if(status!=s[i])
            {
                cnt++;
                status = status == '0' ? '1' : '0';
            }
        }
        return cnt;
    }
};

//000 ----> 101
// 111
// 100
// 101

// 00000 ----> 10111

// 11111
// 10000
// 10111

// 001011101
// 000000000
// 001111111
// 001000000
// 001011111
// 001011100
// 001011101