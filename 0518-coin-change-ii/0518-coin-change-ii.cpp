class Solution {
public:
    int solve( int tar ,vector<int>&S, int ind  , vector<vector<int>>&dp)
    {
       if(ind==0){
            if(tar%S[ind]==0)
            return 1;

            else
            return 0;
        }
        if(dp[ind][tar]!=-1)
           return dp[ind][tar] ; 
        
        int nottake = solve(tar , S , ind-1  ,dp) ; 
        int take = 0 ; 
        if(S[ind]<=tar)
            take = solve(tar-S[ind] , S , ind , dp ) ; 
        
        return dp[ind][tar] = (take+ nottake) ; 
    }
    int change(int n, vector<int>&S) {
    vector<int>dp(n+1 ,0) ;
        vector<int>temp(n+1 , 0) ; 
     //  return  solve(n , S , S.size()-1 , dp) ; 
        for(int i =0 ; i<=n ; i++)
        {
            if(i%S[0]==0)
                dp[i] = (i%S[0]==0) ; 
        }
        
        for(int i =1 ;i <S.size() ; i++){
            for(int j =0 ; j<=n ; j++){
                int nottake = dp[j] ; 
                int take = 0 ; 
                if(S[i]<=j)
                    take = temp[j-S[i]] ;
                temp[j] = (take+ nottake) ; 
            }
            dp = temp  ; 
        }
        return dp[n]  ; 
    }
     
};