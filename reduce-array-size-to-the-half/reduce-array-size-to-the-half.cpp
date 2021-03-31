class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i = 0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        vector<int> v;
        for(auto m : mp)
        {
            v.push_back(m.second);
        }
        sort(v.rbegin(),v.rend());
        int n = arr.size();
        int i = 0,j=0;
        while(i<n/2)
        {
            i += v[j];
            j++;
        }
        return j;
    }
};