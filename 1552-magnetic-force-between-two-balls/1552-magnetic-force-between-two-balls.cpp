class Solution {
public:
 bool valid(vector<int> &A, int M, int m) {
        int prev = 0;
        for (int i = 1, j = 1; i < m; ++i) {
            while (j < A.size() && A[j] < A[prev] + M) ++j;
            if (j >= A.size()) return false;
            prev = j;
        }
        return true;
    }
    int maxDistance(vector<int>& A, int m) {
         sort(begin(A), end(A));
        if (m == 2) return A.back() - A[0];
        int L = 0, R = A.back() - A[0];R++;
        while (L +1< R) {
            int M = (L + R+1) / 2;
            if (valid(A, M, m)) L = M ;
            else R = M ;
        }
        return L;
    }
};