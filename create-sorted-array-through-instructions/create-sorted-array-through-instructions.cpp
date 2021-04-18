//fenwick tree
class Solution {
public:
    static const int m = 100001;
    static const int mod = 1e9 + 7;
    int t[m];

    void incr(int i) {
        for (; i < m; i += i & -i) {
            t[i] += 1;
        }
    }
    
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += t[i];
        }
        return sum;
    }
    
    int createSortedArray(vector<int>& A) {
        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            ans += min(query(A[i] - 1), i - query(A[i]));
            ans %= mod;
            incr(A[i]);
        }
        return ans;
    }
};