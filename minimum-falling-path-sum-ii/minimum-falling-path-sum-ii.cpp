class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> dp;
        dp = arr[n-1];
        for(int i = n-2;i>=0;i--)
        {
            int first_min = INT_MAX , second_min = INT_MAX,first_index;
            for(int j = 0;j<n;j++)
            {
               if(first_min > dp[j])
               {
                   first_min = dp[j];
                   first_index = j;
               }
            }
            for(int j = 0;j<n;j++)
            {
                if(j == first_index)
                    continue;
                if(second_min > dp[j])
                    second_min = dp[j];
            }
            for(int j = 0;j<n;j++)
            {
                if (j==first_index) dp[j]=arr[i][j]+second_min ;  
                else dp[j] = arr[i][j]+first_min ;
            }
        }
         return *min_element(dp.begin(),dp.end());
    }
};
