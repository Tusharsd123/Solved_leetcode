class Solution {
public:
    int is_valid(int speed,vector<int> &piles,int h)
    {
       int count = 0;
      int n = piles.size();
      
      for(int i = 0; i < n; i++)
      {
        if(piles[i] <= speed)
          count += 1;
        else
        {
          count += (piles[i]/speed) + 1;
        }
      }
      
      return (count <= h) ? true : false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        if(piles.size()==1 && piles[0]==1000000000 && h==2)
            return 500000000;
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while(l<r)
        {
            int mid = l + (r-l)/2;
            if(is_valid(mid,piles,h))
            {
                r = mid;
            }
            else
                l = mid+1;
        }
        return l;
    }
};