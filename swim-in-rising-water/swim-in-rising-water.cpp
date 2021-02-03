class Solution {
public:
    //Binary Search and dfs
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};
    bool dfs(vector<vector<int>> &grid,vector<vector<bool>> &visited,int water_limit,int row,int col,int n)
    {
        visited[row][col] = true;
        for(int i = 0;i<4;i++)
        {
            int a = row + x[i];
            int b = col + y[i];
            if(a>=0 && a<n && b>=0 && b<n && visited[a][b]==false && grid[a][b]<=water_limit)
            {
                if(a == n-1 && b == n-1)
                    return true;
                if(dfs(grid,visited,water_limit,a,b,n))
                    return true;
            }
        }
        return false;
    }
    bool valid(vector<vector<int>> &grid,int x)
    {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        return dfs(grid,visited,x,0,0,grid.size());
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = grid[0][0];
        int high = n*n - 1;
        while(low < high)
        {
            int mid = low + (high - low)/2;
            if(valid(grid,mid))
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};