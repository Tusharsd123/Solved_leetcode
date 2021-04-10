class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int s, int d, int K) {
       unordered_map<int,vector<pair<int,int>>> g;
        for(const auto &e : flights)
              g[e[0]].emplace_back(e[1],e[2]);
        int ans = INT_MAX;
        queue<pair<int,int>> q;
        q.push({s,0});
        int steps = 0;
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0;i<n;i++)
            {
                pair<int,int> p = q.front();
                q.pop();
                int u = p.first;
                int w = p.second;
                
                if(u==d)
                    ans = min(ans,w);
                for(auto x : g[u])
                {
                    if(w + x.second > ans)
                        continue;
                    q.push({x.first,x.second+w});
                }
            }
            if(steps++ > K)
                break;
        }
        return ans==INT_MAX?-1:ans;
    }
};