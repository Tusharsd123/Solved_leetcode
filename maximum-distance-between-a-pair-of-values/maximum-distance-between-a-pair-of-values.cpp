class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i=0,j=0,ans=0;
        while(i<len1 && j<len2)
        {
            if(nums1[i]<=nums2[j])
            {
                ans = max(ans,j-i);
                j++;
            }
            else
                i++;
        }
        return ans;
    }
};