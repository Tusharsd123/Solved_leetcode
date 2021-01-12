class Solution {
public:
    int integerBreak(int n) {
        if(n<=2)
            return 1;
        vector<int> matrix(n+1,0);
        matrix[1] = 0;
        matrix[2] = 1;
        for(int i = 3;i<=n;i++)
        {
            for(int j = 1;j<i;j++)
            {
               matrix[i] = max(matrix[i],max(j*(i-j),j*matrix[i-j]));
            }
        }
        return matrix[n];
    }
};
​
​
​
