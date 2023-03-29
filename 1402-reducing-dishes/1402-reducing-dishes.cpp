class Solution {
public:

    int solve(vector<int>&s , int idx , int time ,vector<vector<int>>&dp )
    {
        if(idx == s.size()) return 0 ; 
        if(dp[idx][time]!=-1) return dp[idx][time];
        
        return dp[idx][time]=max(solve(s,idx+1,time,dp),(s[idx]*time)+solve(s,idx+1,time+1,dp));
    }
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end()) ; 
       vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
       // return solve(s, 0 , 1 ,dp);
         
      for(int i = s.size() - 1 ; i>= 0 ; i--)
        {
            for(int j = i ; j>= 0 ; j--)
            {
                if(i == s.size()-1 )
                    dp[i][j] = max(0, s[i]*(j+1));
                else
                {
                    dp[i][j] = max(dp[i+1][j], s[i] * (j+1)  + dp[i+1][j+1]);
                }
            }
        }
        
        return dp[0][0];
    }
};