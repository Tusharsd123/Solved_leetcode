class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
         return atMost(A,K)-atMost(A,K-1);
    }
    int atMost(vector<int> &A,int K)
    {
        int res = 0,i = 0;
        unordered_map<int,int> mp;
        for(int j = 0;j<A.size();j++)
        {
            if(!mp[A[j]]++)
            {
                K--;
            }
            while(K<0)
            {
                if(!--mp[A[i]])
                    K++;
                i++;
            }
            res += j-i+1;
        }
        return res;
    }
};