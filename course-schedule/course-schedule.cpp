class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n,vector<int>());
        vector<int> indegree(n,0);
        for(auto &p : pre)
        {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for(int i = 0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            n--;
            for(auto next : adj[curr])
            {
                if(--indegree[next]==0)
                    q.push(next);
            }
        }
        return n==0;
    }
};
