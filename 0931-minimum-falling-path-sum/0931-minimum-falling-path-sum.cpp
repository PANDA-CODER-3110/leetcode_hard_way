class Solution {
public:
    int m ; 
    int utility(vector<vector<int>>&matrix,vector<vector<int>>&dp,int i,int n ,int j )
    {
        if(j<0 || j>=n)
            return 1e9;
       if(i==m-1)return matrix[i][j]; 
        if(dp[i][j]!=-1)  return dp[i][j] ; 
        return dp[i][j] = matrix[i][j]+min(utility(matrix,dp,i+1,n,j),min(utility(matrix,dp,i+1,n,j-1),utility(matrix,dp,i+1,n,j+1)));
           
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
     m =matrix.size();
        int  n = matrix[0].size();
        vector<int>dp(m,0);
        int mini =INT_MAX;
        
        for(int i =0 ; i<n;i++)
            dp[i] = matrix[0][i] ; 
        
    for(int i=1 ; i<m;i++)
    { vector<int>temp(m,0);
        for(int j=0 ; j<n;j++)
        {
            int left = matrix[i][j] , right = matrix[i][j] , down = matrix[i][j] ; 
            if(j==0)
               left +=1e9 ; 
            else
                left+=dp[j-1] ; 
            down+=dp[j] ; 
            if(j==n-1)
                right+=1e9 ; 
            else
                right+=dp[j+1] ; 
            
            temp[j] = min({left , right , down}) ; 
        }
     dp = temp ; 
    }
        
        for(int i=m-1; i<m;i++)
        {
            for(int j=0 ; j<n;j++)
            {
                mini = min(mini , dp[j]);
            }
            cout<<endl;
        }
        return mini ;
    }
};