class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp,int m,int n)
    {   
	    if(i<0 || j<0) return 1e9 ;// If index is out of bound then returning large value
        if(i==0 && j== 0)return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up =grid[i][j]+solve(i-1,j,grid,dp,m,n);
        int left =grid[i][j]+solve(i,j-1,grid,dp,m,n) ;
        return dp[i][j]=min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>dp(n,0);
      //  return solve(m-1,n-1,grid,dp,m,n);
        
        for(int i =0 ; i<m;i++){
            vector<int>temp(n, 0) ; 
            for(int j =0 ; j<n;j++){
                if(i==0 && j==0)
                    temp[j] =grid[i][j] ; 
                else{
                    int down = grid[i][j] , right = grid[i][j] ; 
                    if(i>0) down+=dp[j] ; 
                    else down+=1e9 ; 
                    if(j>0) right+=temp[j-1] ; 
                    else right+=1e9 ; 
                       
                    temp[j] = min(down , right) ; 
                }
            }
            dp = temp ; 
        }
        return dp[n-1]  ; 
    }
};