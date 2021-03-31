class Solution {
public:
    //LIS O(nlogn) - mono-stack based approach
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto t : target)
        {
            mp[t] = mp.size();
        }
        vector<int> stack;
        for(auto a : arr)
        {
            auto it = mp.find(a);
            if(it!=mp.end())
            {
                if(stack.empty() || stack.back()<it->second)
                    stack.push_back(it->second);
                else
                    *lower_bound(stack.begin(),stack.end(),it->second) = it->second;
            }
        }
        return target.size()-stack.size();
    }
};