class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int mod = 1000000007;
    int memo(int n, int k, vector<vector<int>> &dp) {
        // base case
        if (k <= 0)
            return k == 0;
        if (dp[n][k] != -1)
            return dp[n][k];

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans +  memo(n - 1, k - i,dp))%mod;
        }
        return dp[n][k] = ans;
    }


    int tabulation(int n, int k){
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                int tmp = 0;
                for (int x = 0; x < min(i, j + 1); x++) {
                    tmp = (tmp + dp[i - 1][j - x]) % mod;
                }
                dp[i][j] = tmp;
            }
        }

        return dp[n][k];
    }
    int kInversePairs(int n, int k) {

        // ////memo - TLE -- Testcases passed, but took too long.
        // vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        // return memo(n,k, dp);





        ////tabulation 
        return tabulation(n,k);
        
    }
};