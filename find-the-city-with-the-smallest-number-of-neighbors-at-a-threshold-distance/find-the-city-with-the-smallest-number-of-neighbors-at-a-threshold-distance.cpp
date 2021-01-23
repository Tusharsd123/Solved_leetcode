class Solution {
public:
    vector<pair<int,int>> adj[100005];
    int dijkstra(int x ,int n , int d){
        priority_queue<pair<int,int>> q; 
        int distance[n+1];
        int visited[n+1];
        memset(visited,0,sizeof(visited));
        for (int i = 0; i < n; i++) distance[i] = 1e9;
        distance[x] = 0;
        q.push({0,x});
        while (!q.empty()) {
            int a = q.top().second; q.pop();
            if (visited[a] == 0){
                visited[a] = 1;
                for (auto u : adj[a]) {
                    int b = u.first, w = u.second;
                    if (distance[a]+w < distance[b]) {
                        distance[b] = distance[a]+w;
                        q.push({-distance[b],b});
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(i != x){
                if(distance[i] <= d) ans++;
            }
        }
        return ans;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(int i = 0;i<edges.size();i++){
            int x = edges[i][0];
            int y = edges[i][1];
            int w = edges[i][2];
            adj[x].push_back({y,w});
            adj[y].push_back({x,w});
        }
        int sum = 1e9;
        for(int i = 0;i<n;i++){
            int y = dijkstra(i,n,distanceThreshold);
            sum = min(sum,y);
        }
        int h = -1;
        for(int i = 0;i<n;i++){
            int y = dijkstra(i,n,distanceThreshold);
            if(y == sum) h = i;
        }
        return h;
    }
};
