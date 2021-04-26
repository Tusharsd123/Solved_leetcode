class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
          int len = seats.size();
          int max_dist = 0;
          vector<int> dists;
        for(int i = 0;i<len;i++)
            if(seats[i]==1)
                dists.push_back(i);
        for(int i = 1;i<dists.size();i++)
              max_dist = max(max_dist,dists[i]-dists[i-1]);
        int n = dists.size()-1;
        int a = dists[0]-0;
        int b = len-1-dists[n];
        return max(a,max(b,max_dist/2));
    }
};