class Solution {
public:
    typedef pair<int,int> P;
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int ans = 0,n = apples.size();
        priority_queue<P,vector<P>,greater<P>> pq;
        int i = 0;
        while(i<n || pq.size())
        {
            if(i<n && apples[i]>0)
                pq.push({i+days[i]-1,apples[i]});
            while(pq.size() && pq.top().first<i)
                 pq.pop();
            if(pq.size())
            {
              auto p = pq.top();
              pq.pop();
              if(p.second>1)
                  pq.push({p.first,p.second-1});
              ans++;
            }
            i++;
        }
        return ans;
    }
};