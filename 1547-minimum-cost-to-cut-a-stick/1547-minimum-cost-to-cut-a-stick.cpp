class Solution {
public:
    int solve(vector<int>& cuts, int i , int j ,vector<vector<int>>&dp ){
        if(i>j) return 0 ; 
        int mini = INT_MAX ; 
        if(dp[i][j]!=-1)
            return dp[i][j] ; 
        for(int k = i ; k<=j ; k++){
            int steps = cuts[j+1] - cuts[i-1] +solve(cuts ,i , k-1 ,dp)+solve(cuts , k+1 , j , dp) ;
            mini = min(mini , steps) ; 
        }
        return dp[i][j] = mini ; 
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size() ; 
        cuts.push_back(0) ; 
        cuts.push_back(n) ; 
        sort(cuts.begin() , cuts.end()) ; 
        vector<vector<int>>dp(c+2,vector<int>(c+2,0) ) ; 
    
      //  return solve(cuts, 1 , c , dp) ; 
        
        
        for(int i = c ; i>=1 ; i--){
            for(int j = i ; j<=c ; j++){
                if(i>j) 
                    continue ; 
                int mini = INT_MAX ; 
                for(int k =i ; k<=j;k++)
                {
                     int steps = cuts[j+1] - cuts[i-1] +dp[i][k-1]+dp[k+1][j] ; 
                    mini = min(mini , steps) ; 
                }
                dp[i][j] = mini ; 
            }
        }
        
        return dp[1][c] ; 
    }
};