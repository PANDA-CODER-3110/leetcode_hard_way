vector<int>dp(10001,-1);
class Solution {
public:
    int solve(int n){
        if(n<=0)    
            return 0;
        if(dp[n]!=-1)   return dp[n];
        int ans = INT_MAX;
        for(int i=1;i*i<=n;i++){
            int sqr = i*i;
            int count =1+solve(n-sqr);
            ans = min(ans,count);
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        return solve(n);
    }
};