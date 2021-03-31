class Solution {
public:
    static bool my_sort(vector<int> &a,vector<int> &b)
    {
        return a[1]==b[1]?a[0]<b[0]:a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 0;
        int last = INT_MIN;
        sort(points.begin(),points.end(),my_sort);
        for(int i = 0;i<points.size();i++)
        {
            if(last!=INT_MIN && points[i][0]<=last)
                continue;
            last = points[i][1];
            count++;
        }
        return count;
    }
};