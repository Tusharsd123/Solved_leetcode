// Backtracking Algo
class Solution {
public:
    int ans = INT_MAX;
    
    void backtrack(int start, vector<int> &v,vector<int> &cookies,int k){
        if(start==cookies.size()){
            int maxm = INT_MIN;
            for(int i = 0;i<k;i++)
                maxm = max(maxm,v[i]);
            ans = min(ans,maxm);
            return;
        }
        
        for(int i = 0;i<k;i++){
            v[i] += cookies[start];
            backtrack(start+1,v,cookies,k);
            v[i] -= cookies[start];
            if(v[i]==0)
                break;
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> v(k,0);
        backtrack(0,v,cookies,k);
        return ans;
    }
};