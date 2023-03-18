class Solution {
public:
    int lo = 501 ; 
  //- --------------------------------------- memoization answer-----------------------------------------//
    // int solve(string&x, string&y ,int i , int j,vector<vector<int>>&dp )
    // {
    //     if(x.size()==i ) return y.size()-j ; 
    //     if(y.size()==j) return x.size()-i ; 
    //     if(dp[i][j]!=-1)
    //         return dp[i][j]; 
    //     if(x[i]==y[j])
    //         return  dp[i][j]= solve(x,y,i+1,j+1,dp); 
    //     else
    //     {
    //         return dp[i][j] =   1+ min(solve(x,y,i+1,j+1,dp),min(solve(x,y,i+1,j,dp),solve(x,y,i,j+1,dp))); 
    //     }
    // }
    int minDistance(string word1, string word2) {
        if (word1.length() == 0) return word2.length();
        int n = word1.length(); 
        int m = word2.length(); 
        if (word2.length() == 0) return word1.length();
          vector<vector<int>>dp(601,vector<int>(601,0)); 
        // return solve(word1,word2,0,0,dp); 
         for (int i = 0; i <= word1.length(); i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.length(); j++) {
            dp[0][j] = j;
        }
         for(int i=0 ;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
              if(word1[i]==word2[j])
                  dp[i+1][j+1] = dp[i][j]; 
                else
                {
                    dp[i+1][j+1] = 1+ min(dp[i][j+1],min(dp[i+1][j],dp[i][j])); 
                }
            }
        }
        return dp[n][m] ; 
      
    }
};