class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp,int m,int n)
    {   
	    if(i<0 || j<0) return 1e9 ;// If index is out of bound then returning large value
        if(i==0 && j== 0)return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up =grid[i][j]+solve(i-1,j,grid,dp,m,n);
        int left =grid[i][j]+solve(i,j-1,grid,dp,m,n);
        return dp[i][j]=min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int> (n+1,-1));
        return solve(m-1,n-1,grid,dp,m,n);
    }
};