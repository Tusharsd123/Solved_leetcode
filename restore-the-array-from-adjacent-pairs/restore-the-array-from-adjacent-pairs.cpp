class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& arr) {
       unordered_map<int,vector<int>> ps;
       for(auto &p : arr)
       {
           ps[p[0]].push_back(p[1]);
           ps[p[1]].push_back(p[0]);
       }
        vector<int> res;
        for(auto &m : ps)
        {
            if(m.second.size()==1)
            {
                res.push_back(m.first);
                res.push_back(m.second[0]);
                break;
            }
        }
        while(res.size() < arr.size()+1)
        {
            auto tail = res.back();
            int prev = res[res.size()-2];
            auto &next = ps[tail];
            if(next[0]!=prev)
                res.push_back(next[0]);
            else
                res.push_back(next[1]);
        }
        return res;
    }
};