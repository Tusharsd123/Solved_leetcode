​
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()==0||A.size()==1||A.size()==2)
            return 0;
          int count = 0;
        for(int s = 0;s<A.size()-2;s++)
        {
            int d = A[s+1]-A[s];
            for(int e = s+2;e<A.size();e++)
            {
                if(A[e]-A[e-1]==d)
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};
