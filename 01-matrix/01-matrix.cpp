//::multi source shortest path problem::
class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
       int n = matrix.size();
       int m = matrix[0].size();
       queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(m,-1));
       for(int i =0;i<n;i++)
       {
           for(int j =0;j<m;j++)
           {
               if(matrix[i][j]==0)
               {
                   q.push({i,j});
                   dist[i][j] = 0;
               }
           }
       }
        
        while(!q.empty())
        {
            pair<int,int> curr = q.front();
            q.pop();
            for(int k =0;k<4;k++)
            {
                int a = curr.first + x[k];
                int b = curr.second + y[k];
                if(a>=0 && a<n && b>=0 && b<m && dist[a][b]==-1)
                {
                    dist[a][b] = dist[curr.first][curr.second]+1;
                    q.push({a,b});
                }
            }
        }
        
        return dist;
    }
};
