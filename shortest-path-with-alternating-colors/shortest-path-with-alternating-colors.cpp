class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<pair<int,int>>> g(n);
        for(auto v : red_edges)
            g[v[0]].push_back({v[1],0});
        for(auto u : blue_edges)
            g[u[0]].push_back({u[1],1});
        vector<vector<int>> vCost(n,vector<int>(2,-1));
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({0,1});
        vCost[0] = {0,0};
        while(!q.empty())
            {
                pair<int,int> p = q.front();
                q.pop();
                for(auto v : g[p.first])
                {
                    if(v.second==p.second || vCost[v.first][v.second]!=-1)
                        continue;
                    vCost[v.first][v.second] = vCost[p.first][p.second]+1;
                    q.push({v.first,v.second});
                }
            }
        vector<int> res;
        for(auto v : vCost)
            {
                sort(v.begin(),v.end());
                res.push_back(v[0]!=-1?v[0]:v[1]);
            }
        return res;
    }
};