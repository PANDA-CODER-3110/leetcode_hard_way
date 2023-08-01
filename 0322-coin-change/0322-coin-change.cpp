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
    int coinChange(vector<int>& c, int amount) {
        vector<int>prev(amount+1,0)   ;
        vector<int>cur(amount+1 , 0)  ;
        // int ans = solve(coins , amount , coins.size()-1 , dp) ; 
         for(int i=0; i<=amount; i++){
        if(i%c[0] == 0)  
            prev[i] = i/c[0];
        else prev[i] = 1e9;
    }
        
        for(int i =1 ;i<c.size();i++){
            for(int j =0 ; j<=amount ; j++){
                    int nottake = 0 +prev[j] ; 
                    int take = 1e9 ; 
                    if(c[i]<=j) 
                        take = 1+cur[j - c[i]] ; 
                
                 cur[j] = min(take , nottake ) ; 
                
              
            }
            prev = cur ; 
        }
        
  int ans = prev[amount];
    if(ans >=1e9) return -1;
    return ans;
    }
};