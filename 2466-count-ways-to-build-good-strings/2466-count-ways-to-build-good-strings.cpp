class Solution {
public:
    int mod=1e9+7;
    int helper(int low,int high,int zero,int one,int count,vector<int>& dp){
        if(count>high){return 0;}
        int ans=0;
        if(dp[count]!=-1)return dp[count];
        if(count<=high && count>=low){ans+=1;}
        int ans1 = helper(low,high,zero,one,count+zero,dp)%mod;
        int ans2 = helper(low,high,zero,one,count+one,dp)%mod;
        return dp[count] = (ans+(ans1+ans2)%mod)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        return helper(low,high,zero,one,0,dp);
    }
};