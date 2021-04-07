class Solution {
public:
    int is_valid(int threshold,vector<int> &weights,int D)
    {
        int sum = 0,days=1;
        for(int i = 0;i<weights.size();i++)
        {
           if(weights[i]>threshold || days>D)
              return false;
           if(sum + weights[i] > threshold)
           {
               sum = weights[i];
               days++;
           }
            else
                sum += weights[i];
        }
        return days<=D;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int l = 1;
        int r = 25000000;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(is_valid(mid,weights,D))
            {
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return l;
    }
};