class Solution {
public:
    int solve(int i , int j , string s, string t , vector<vector<int>>&dp){
        if(j<=0)
            return 1 ; 
        if(i<=0)
            return 0 ; 
        if(dp[i][j]!=-1)
            return dp[i][j] ;
        
        if(s[i]==t[j])
            return dp[i][j]=solve(i-1 , j-1 , s , t , dp) + solve(i-1 , j , s, t , dp) ; 
        else return  dp[i][j]=solve(i-1 , j , s, t , dp) ;  
    }
    int numDistinct(string s, string t) {
        vector<vector<double>>dp(s.size()+1 , vector<double>(t.size()+1,0)) ; 
      //  return solve(s.size()-1 , t.size()-1 ,s, t ,dp) ; 
        for(int i =0 ; i<=s.size();i++)dp[i][0]=1 ; 
       
        for(int i =1 ; i<=s.size();i++){
            for(int j =1 ; j<=t.size();j++){
               if(s[i-1]==t[j-1])
                   dp[i][j] = dp[i-1][j-1]+dp[i-1][j] ;
                else 
                    dp[i][j] = dp[i-1][j]  ;  
            }
        }
        return dp[s.size()][t.size()] ; 
    }
};