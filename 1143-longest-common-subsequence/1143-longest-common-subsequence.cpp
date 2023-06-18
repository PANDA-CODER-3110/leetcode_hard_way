class Solution {
public:
    /// --------------------------------- memoization------------------------------------------//
    // int solve(int n , int  m,string&x, string&y,int dp[][1001] )
    // {
    //     if(n==0 || m==0 )
    //         return 0 ; 
    //     if(dp[n][m]!=-1)
    //         return dp[n][m]; 
    //     if(x[n-1]==y[m-1])
    //         return dp[n][m]= 1+solve(n-1,m-1,x,y,dp); 
    //     else
    //         return dp[n][m]= max(solve(n-1,m,x,y,dp),solve(n,m-1,x,y,dp)); 
    // }
    int longestCommonSubsequence(string x, string y) {
      
    int n = x.size(), m = y.size(); 
         int dp[1001][1001];
        // for(int i=0;i<1001;i++){
        //     for(int j=0;j<1001;j++){
        //         dp[i][j]=-1;
        //     }
        // }
        // return solve(n, m , x, y ,dp); 
        for(int i=0 ; i<=n;i++)
        {
            for(int j=0 ; j<=m;j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0 ; 
                else if(x[i-1] == y[j-1])
                    dp[i][j] = 1+dp[i-1][j-1]; 
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]); 
                    
            }
        }
        return dp[n][m]; 
        
    }
};