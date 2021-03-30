class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        for(int i = 0;i<A.size() && K>0;i++)
        {
            if(A[i]<0)
            {
                A[i] = (-1)*A[i];
                K--;
            }
            else
                break;
        }
        int sum = 0,i=0;
        while(i<A.size())
        {
            sum += A[i];
            i++;
        }
        if(K%2==0)
        {
            return sum;
        }
        else
        {
            sort(A.begin(),A.end());
            return sum- 2*A[0];
        }
        return sum;
    }
};