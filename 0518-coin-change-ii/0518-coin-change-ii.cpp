class Solution {
public:
     int rec(int idx, int tar,  vector<int>& coins,vector<vector<int>> &dp)
    {
        if(idx==0){
            if(tar%coins[idx]==0)
            return 1;

            else
            return 0;
        }
      if(dp[idx][tar]!=-1) return dp[idx][tar];
        int ntk = rec(idx-1,tar,coins,dp);
        int tk = 0;
        if(coins[idx]<=tar){
            tk = rec(idx,tar-coins[idx],coins,dp);
        }

        return dp[idx][tar]=tk+ntk;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));
        return rec(coins.size()-1,amount, coins,dp);
    }
};