class Solution {
public:
    unordered_map<int,vector<int>> g;
    unordered_map<int,bool> visited;
    void create_graph(vector<vector<int>>& edges)
    {
        for(auto e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
    }
    int dfs(int node,int my_cost,vector<bool>& hasApple)
    {
        if(visited[node])
             return 0;
        visited[node] = true;
        int children_cost = 0;
        for(auto x : g[node])
            children_cost += dfs(x,2,hasApple);
        
        if(children_cost==0 && hasApple[node]==false)
            return 0;
        return (children_cost + my_cost);
            
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        create_graph(edges);
        return dfs(0,0,hasApple);
    }
};