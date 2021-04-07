//we have two solutions 
//1. Dijkstra 2. DFS+BS
class Solution {
public:
    typedef pair<int,pair<int,int>> pii;
    int dir_x[4] = {-1,1,0,0};
    int dir_y[4] = {0,0,1,-1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m,vector<int>(n, INT_MAX));
	    dist[0][0] = 0;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,{0,0}}); //{distance,{row,col}}
        while(!pq.empty())
        {
            pii p = pq.top();
            int d = p.first;
            int r = p.second.first;
            int c = p.second.second;
            pq.pop();
            if(d > dist[r][c])
                continue;
            if(r==m-1 && c==n-1)
                return d;
            for(int i = 0;i<4;i++)
            {
                int nr = dir_x[i] + r;
                int nc = dir_y[i] + c;
                
                if(nr>=0 && nc>=0 && nr<m && nc<n)
                {
                    int new_dist = max(d,abs(heights[r][c]-heights[nr][nc]));
                    if(new_dist < dist[nr][nc])
                    {
                        dist[nr][nc] = new_dist;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};