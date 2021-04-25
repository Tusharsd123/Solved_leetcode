class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if(n%W!=0)
            return false;
        map<int,int> mp;
        for(auto c : hand)
            mp[c]++;
        while(!mp.empty())
        {
          int curr = mp.begin()->first;
          for(int i = 0;i<W;i++)
          {
              if(mp[curr+i]==0)
                  return false;
              else if(--mp[curr+i]<1)
                  mp.erase(curr+i);
          }
        }
        return true;
    }
};