class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=stones[i];
       int s=sum/2;
        int ans=INT_MAX;
        bool t[n+1][s+1];
        vector<int> v;
        
        for(int i=0;i<n+1;i++)
            t[i][0]=true;
        for(int i=1;i<s+1;i++)
            t[0][i]=false;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<s+1;j++){
                if(stones[i-1]<=j){
                    t[i][j]=t[i-1][j-stones[i-1]] || t[i-1][j];
                }
                else
                    t[i][j]=t[i-1][j];
            }
        }
        
        
        for(int i=1;i<s+1;i++)
        {
         if(t[n][i] == true)
           v.push_back(i);
        }
        
        for(int i : v){
            ans=min(ans, sum-(2*i));
        }
        return ans;
    }
};
