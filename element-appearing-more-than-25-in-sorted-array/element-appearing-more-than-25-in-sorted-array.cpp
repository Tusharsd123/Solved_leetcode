class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
      int len = arr.size();
        vector<int> candidates = {arr[len/4],arr[len/2],arr[len*3/4]};
        for(auto cand : candidates)
        {
            auto l = lower_bound(arr.begin(),arr.end(),cand);
            auto r = upper_bound(arr.begin(),arr.end(),cand);
            if(4*(distance(l,r))>len)
                return cand;
            }
        return -1;
    }
};