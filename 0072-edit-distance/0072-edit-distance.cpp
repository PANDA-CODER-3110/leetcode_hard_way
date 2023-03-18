class Solution {
public:
    int lo = 501 ; 
  
    int solve(string&x, string&y ,int i , int j,vector<vector<int>>&dp )
    {
        if(x.size()==i ) return y.size()-j ; 
        if(y.size()==j) return x.size()-i ; 
        if(dp[i][j]!=-1)
            return dp[i][j]; 
        if(x[i]==y[j])
            return  dp[i][j]= solve(x,y,i+1,j+1,dp); 
        else
        {
            return dp[i][j] =   1+ min(solve(x,y,i+1,j+1,dp),min(solve(x,y,i+1,j,dp),solve(x,y,i,j+1,dp))); 
        }
    }
    int minDistance(string word1, string word2) {
        if (word1.length() == 0) return word2.length();
        if (word2.length() == 0) return word1.length();
          vector<vector<int>>dp(501,vector<int>(501,-1)); 
         return solve(word1,word2,0,0,dp); 
        
    }
};