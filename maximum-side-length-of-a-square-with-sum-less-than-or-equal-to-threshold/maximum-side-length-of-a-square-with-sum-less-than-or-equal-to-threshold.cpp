class Solution {
public:
    int m,n;
    int is_square_exists(vector<vector<int>> &sums,int threshold,int len)
    {
        for(int i = len;i<=m;i++)
        {
            for(int j = len;j<=n;j++)
            {
                if(sums[i][j] - sums[i-len][j] - sums[i][j-len] + sums[i-len][j-len] <= threshold)
                       return true;
            }
        }
        return false;
    }
    
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> sum(m+1,vector<int>(n+1,0));
        for(int i = 1;i<=m;i++)
        {
            for(int j = 1;j<=n ;j++)
            {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mat[i-1][j-1];
            }
        }
        
        int l = 0;
        int r = min(m,n);
        while(l<=r)
        {
            int mid = (l + r)/2;
            if(is_square_exists(sum,threshold,mid))
                l = mid+1;
            else
                r = mid-1;
        }
        return r;
    }
};