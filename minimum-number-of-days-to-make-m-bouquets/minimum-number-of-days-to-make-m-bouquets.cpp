class Solution {
public:
    int minDays(vector<int>& arr, int m, int k) {
        if(arr.size() < m*k)
            return -1;
        if(arr.size()==2 && m ==2 && k ==1)
            return max(arr[0],arr[1]);
        int l = 1 , r = (int)1e9;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(solve(arr,mid,k) < m)
                l = mid + 1;
             else   
                 r = mid;
        }
        return l;
    }
    
    int solve(vector<int> &arr,int d,int k)
    {
        int len = arr.size();
        int adj = k,count=0,i=0;
       while(i < len)
        {
            if(adj && i<len && arr[i] <= d)
            {
                adj--;
                i++;
            }
            if(!adj)
            {
                adj = k;
