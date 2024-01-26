class Solution {
int mod = pow(10, 9)+7;
    int getAns(int m, int n, int maxMove, int stRow, int stCol, vector<vector<vector<int> > > &dp){
        // base case
        if(stRow >= m || stCol >= n || stRow < 0 || stCol < 0){
            return 1;
        }
        if(maxMove <= 0){
            return 0;
        }
        if(dp[maxMove][stRow][stCol] != -1){
            return dp[maxMove][stRow][stCol];
        }

        int ans = 0;
        ans = (ans + (getAns(m, n, maxMove-1, stRow, stCol+1, dp)%mod))%mod;
        ans = (ans + (getAns(m, n, maxMove-1, stRow, stCol-1, dp)%mod))%mod;
        ans = (ans + (getAns(m, n, maxMove-1, stRow+1, stCol, dp)%mod))%mod;
        ans = (ans + (getAns(m, n, maxMove-1, stRow-1, stCol, dp)%mod))%mod;

        dp[maxMove][stRow][stCol] = ans;
        return dp[maxMove][stRow][stCol];
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int> > > dp(maxMove+1, vector<vector<int> > (m, vector<int> (n, -1)));
        return getAns(m, n, maxMove, startRow, startColumn, dp);
    }
};