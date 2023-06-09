class Solution {
public:
    int atMost(vector<int>& A, int S) {
        if (S < 0) return 0;
        int res = 0, i = 0, n = A.size();
        int sum =0 ; 
        for (int j = 0; j < n; j++) {
           if(A[j]%2==1) sum++ ; 
            while(sum>S)
            {
                if(A[i]%2==1)
                    sum-- ; 
                i++ ; 
            }
            res+= (j-i+1) ; 
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& A, int S) {
        return atMost(A, S) - atMost(A, S - 1);
    } 
};