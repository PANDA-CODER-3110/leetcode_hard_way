class Solution {
public:
   int solve(string x, string y , int m , int n, vector<vector<int>>&dp )
  {
      if(n==x.size() || m==y.size())
      return  0  ; 
      
      if(dp[n][m]!=-1)
      return dp[n][m] ;
      
      if(x[m]==y[n])
      return dp[n][m] =  1 + solve(x,y,m+1 , n+1,dp );
       
       else
        return dp[n][m] = max(solve(x,y,m+1 , n,dp), solve(x,y,m,n+1,dp)) ; 
  }
    int minInsertions(string str) {
  string str2 = str ;
        int n = str.size(); 
     reverse(str2.begin(), str2.end()) ; 
     vector<vector<int>>dp(n+1,vector<int>(n+1,-1)) ; 
     // int ans = solve(str , str2, 0, ,dp) ; 
        for(int i=0;i<=n;i++)
        {
            for(int j=0  ;j<=n;j++)

            {
                if(i==0 || j==0)
                    dp[i][j] = 0 ; 
                else if(str[i-1]==str2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1] ; 
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ; 
            }
        }
     return str.size() - dp[n][n]; 
        
        }
    
};