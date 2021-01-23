class Solution {
public:
    void dfs(int x,int y,vector<vector<int>> &grid,int d = 1)
    {
        if(x<0 || y<0 || x>=grid.size() || y>=grid[x].size() || (grid[x][y]!=0 && grid[x][y] <= d))
            return;
        grid[x][y] = d;
         dfs(x+1,y,grid,d+1);
         dfs(x-1,y,grid,d+1);
         dfs(x,y+1,grid,d+1);
         dfs(x,y-1,grid,d+1);
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j] = 0;
                    dfs(i,j,grid);
                }
            }
        }
        int mx = -1;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]>1)
                    mx = max(mx,grid[i][j]-1);
            }
        }
        return mx;
    }
};
