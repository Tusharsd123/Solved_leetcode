class Solution {
public:
    int minRefuelStops(int t, int f, vector<vector<int>>& st) {
         int len = st.size();
        int ans = 0;
        priority_queue<int>pq;
        int curr = 0;
        for(int i = 0;i<len;i++){
            int dist = min(st[i][0],t) - curr;
            while(!pq.empty()&&f<dist){
                f += pq.top();
                pq.pop();
                ans ++;
            }
            if(f<dist)
                return -1;
            else 
                f -= dist;
            curr = min(st[i][0],t);
            pq.push(st[i][1]);
        }
        int dist = t - curr;
        while(!pq.empty()&&f<dist){
            f += pq.top();
            pq.pop();
            ans ++;
        }
        if(f<dist)
            return -1;
​
        return ans;
    }
};
​
​
// dp[i] (farthest distance) --> i refuelling stops so that i can reach dp[i] >= target
