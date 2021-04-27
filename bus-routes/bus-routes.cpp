class Solution {
public:
    
    int bfs(vector<vector<int>> &routes,unordered_map<int,vector<int>> &bus_stop,int S,int T)
    {
        if(S==T)
            return 0;
        unordered_map<int,bool> vis_stops;
        for(auto itr = bus_stop.begin();itr!=bus_stop.end();itr++)
            vis_stops[itr->first] = false;
        vector<bool> vis_bus(routes.size(),false);
        queue<pair<int,int>> q;
        q.push({S,0});
        vis_stops[S] = true;
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            int curr_stop = p.first;
            int count = p.second;
            if(curr_stop==T)
                return count;
            vector<int> bus_options = bus_stop[curr_stop];
            for(int i = 0;i<bus_options.size();i++)
            {
                int curr_bus = bus_options[i];
                if(vis_bus[bus_options[i]]==true)
                    continue;
                else
                {
                   vector<int> next_stops = routes[curr_bus];
                    for(int j = 0;j<next_stops.size();j++)
                    {
                        if(vis_stops[next_stops[j]])
                            continue;
                        else
                        {
                            q.push({next_stops[j],count+1});
                            vis_stops[next_stops[j]] = true;
                        }
                    }
                }
                vis_bus[curr_bus] = true;
            }
        }
        return -1;
    }
    
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        int n = routes.size();
        if(S==T || n==0)
            return 0;
        unordered_map<int,vector<int>> bus_stop;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<routes[i].size();j++)
            {
                int curr_stop = routes[i][j];
                int curr_bus = i;
                bus_stop[curr_stop].push_back(i);
            }
        }
        return bfs(routes,bus_stop,S,T);
    }
};