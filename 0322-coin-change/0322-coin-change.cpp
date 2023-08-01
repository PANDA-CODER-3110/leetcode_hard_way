class Solution {
public:
    int solve(vector<int>&c, int amt , int ind , vector<vector<int>>&dp){
        if(ind==0){
            if(amt%c[0]==0)
                return amt/c[0] ; 
            else return 1e9 ; 
        }
        if(dp[ind][amt]!=-1)
            return dp[ind][amt] ; 
        
        int nottake = solve(c , amt , ind -1 , dp) ; 
        int take = 1e9  ; 
        if(c[ind]<=amt) take = solve(c , amt - c[ind] , ind , dp )+1 ; 
        return dp[ind][amt] = min(take , nottake ) ; 
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1))   ; 
        int ans = solve(coins , amount , coins.size()-1 , dp) ; 
        return (ans ==1e9)?-1 : ans ; 
    }
};