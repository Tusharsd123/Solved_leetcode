class Solution {
public:
    void dfs(vector<bool> &visited,vector<vector<int>> &adj,int x)
     {
           visited[x] = true;
           for(auto u : adj[x])
               if(!visited[u])
                     dfs(visited,adj,u);
     }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<vector<int>> adj(rooms.size());
        int components = 0;
        for(int i = 0;i<rooms.size();i++)
        {
            for(int j = 0;j<rooms[i].size();j++)
            {
                adj[i].push_back(rooms[i][j]);
            }
        }
        vector<bool> visited(rooms.size(),false);
        for(int i = 0;i<rooms.size();i++)
          {
            if(!visited[i])
            {
                dfs(visited,adj,i);
                components++;
            }
        } 
        return components==1?true:false;
    }
};