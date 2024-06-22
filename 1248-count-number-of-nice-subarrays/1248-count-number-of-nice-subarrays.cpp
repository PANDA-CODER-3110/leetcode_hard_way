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
    int numberOfSubarrays(vector<int>&nums, int k) {
        // return atMost(A, S) ;
        int n = nums.size();
        vector<int> count(n+1, 0);
        count[0] = 1;
        int ans = 0, t = 0;
        for(int v : nums){
            t += v&1;
            if(t-k >= 0){
                ans += count[t-k];
            }
            count[t]++;
        }
        return ans;
    } 
};