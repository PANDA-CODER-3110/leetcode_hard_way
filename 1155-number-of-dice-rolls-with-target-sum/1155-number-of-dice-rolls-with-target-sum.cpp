class Solution {
public:
int m=1000000007;
    int help(int n , int  k , int target , vector<vector<long long>>&dp){
        if(n==0 && target==0) return 1;
        if(n==0 || target==0) return 0;
        if(target<0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        long long ans=0;
        for(int i=1;i<=k;i++){
            ans=(ans%m+(help(n-1,k,target-i,dp))%m)%m;
        }
        return dp[n][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n+1,vector<long long>(target+1,-1));
        return help(n,k,target,dp);
        
    }
};