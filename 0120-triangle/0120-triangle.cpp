class Solution {
public:
    int solve(int i , int j ,vector<vector<int> > &t , int n  ,vector<vector<int>>&dp  )
    {
        if(i==n-1) return t[n-1][j] ; 
        
        if(dp[i][j]!=-1)
            return dp[i][j] ; 
        int d = t[i][j] + solve(i+1 , j , t ,n , dp) ; 
        int dg = t[i][j] + solve(i+1, j+1 , t , n,dp) ; 
        return dp[i][j] = min(d , dg ) ; 
    }
   int minimumTotal(vector<vector<int> > &triangle) {
       int n  = triangle.size() ;  
       vector<vector<int>>dp(n ,vector<int>(n, -1)) ; 
   return solve(0 , 0 , triangle , n , dp) ; 
}
};