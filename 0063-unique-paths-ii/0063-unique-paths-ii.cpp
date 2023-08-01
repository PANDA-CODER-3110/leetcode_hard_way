class Solution {
public:
    int solve(int i  , int j ,vector<vector<int>>&mat , vector<vector<int>>&dp  )
    {
        if(i<0 ||  j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j]==1) return 0 ; 
        
        if(i==0 && j==0 ) return 1 ; 
        if(dp[i][j]!=-1)
            return dp[i][j] ; 
        return dp[i][j] = solve(i-1 , j ,mat , dp)+solve(i , j-1 , mat , dp ) ;  
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        
        int n = mat.size()  ;
        int m = mat[0].size() ;
        vector<vector<int>>dp( n , vector<int>(m ,0)) ; 
       // return solve(n-1 , m-1 , obstacleGrid , dp) ; 
        for(int i =0 ; i<n;i++){
            for(int j =0 ; j<m;j++){
                if(mat[i][j]==1)
                    dp[i][j] = 0 ; 
                else if(i==0 && j==0)
                    dp[i][j] = 1 ; 
                else
                {
                    int up =0 ; 
                    int left  =0 ; 
                    if(i>0)
                        up = dp[i-1][j] ; 
                    if(j>0)
                        left = dp[i][j-1] ; 
                    
                    dp[i][j] = up+left  ; 
                }
                
            }
        }
        return dp[n-1][m-1] ;  
    }
};