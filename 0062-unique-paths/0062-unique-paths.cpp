class Solution {
public:
    
     int f (int a , int b , int i , int j ,vector<vector<int>>&dp )
    {
        if(i<0 ||  j<0)
        return  0 ; 
        if(i==a || j==b) return 1 ; 
        
        if(dp[i][j]!=-1)
        return dp[i][j] ;
         
         return dp[i][j]  = f(a,b,i-1,j,dp)+f(a,b,i,j-1,dp) ; 
         
        
    }
    int uniquePaths(int m, int n) {
        
          vector<int>dp(n,-1) , temp(n , 0);
       // return f(0, 0 ,m-1 , n-1 , dp); 
       // vector<vector<int>>dp(m,vector<int>(n,-1));
        
        for(int i=0 ; i<m;i++)
        {
            vector<int>temp(n ,0) ; 
            for(int j=0 ; j<n;j++)
            {
                if(i==0 || j==0)
                {
                    temp[j] =1 ; 
                }
                else
                {
                    temp[j] = dp[j]+temp[j-1]; 
                }
                    
            }
            dp = temp ; 
        }
        return dp[n-1]; 
        
    }
};