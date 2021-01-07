class Solution {
public:
    int maximumSum(vector<int>& arr) {
        //base cases
        int len = arr.size();
        if(len==1)
            return arr[0];
        int droped = max(arr[0],arr[1]);
        int not_droped =  max(arr[0]+arr[1],arr[1]);
        int ans = max(droped,not_droped);
        for(int i = 2;i<len;i++)
        {
            droped = max(not_droped,droped+arr[i]);
            not_droped = max(not_droped+arr[i],arr[i]);
            ans = max(ans,max(droped,not_droped));
        }
        return ans;
    }
};
