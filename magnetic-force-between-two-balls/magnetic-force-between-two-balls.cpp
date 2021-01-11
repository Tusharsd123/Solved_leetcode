//As a rule of thumb, use m = l + (r-l)//2 with l = m + 1 and r = m, and use m = r - (r-l)//2 with l = m and r = m - 1. This can prevent m from stucking at r (or l) after the updating step.
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int l = 0, r = position.back()-position.front();
        while(l<r)
        {
            int mid = r - (r-l)/2;
            if(solve(position,mid)>=m)
                l = mid;
            else
                r = mid-1;
        }
        return l;
    }
    
    int solve(vector<int> &position,int d)
    {
        int ans = 1, curr = position[0];
        for(int i = 1;i<position.size();i++)
        {
            if(position[i]-curr >=d)
            {
                ans++;
                curr = position[i];
            }
        }
        return ans;
    }
    
};
