class Solution {
public:
    int fill(vector<vector<int>>& g, int i, int j,int &k) {
    if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || !g[i][j])
        return 0;
    k++;
    return (g[i][j] = 0) + fill(g, i + 1, j,k) + fill(g, i, j + 1,k) 
        + fill(g, i - 1, j,k) + fill(g, i, j - 1,k);
}
    int numEnclaves(vector<vector<int>>& g) {
        int x=0,y=0;
        for (int i = 0; i < g.size(); ++i)
          for (int j = 0; j < g[i].size(); ++j)
             if (i * j == 0 || i == g.size() - 1 || j == g[i].size() - 1)
                fill(g, i, j,x);
    for (int i = 0; i < g.size(); ++i)
    {
        for (int j = 0; j < g[i].size(); ++j)
        {
            if(g[i][j]==1)
                fill(g,i,j,y);
        }
    }   
    return y;
    }
};
