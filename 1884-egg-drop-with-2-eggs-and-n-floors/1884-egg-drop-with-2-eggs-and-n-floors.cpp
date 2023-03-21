class Solution {
public:
    int solve(int e , int f,vector<vector<int>>&dp)
    {
        if(e==1) return f ;
        if(f==0 || f==1 )
            return f ;
        if(dp[e][f]!=-1) return dp[e][f];
         int minn = INT_MAX; 
        for(int i=1;i<f;i++)
        {
            minn = min(minn,max(1+solve(e-1,i-1,dp),1+solve(e,f-i,dp)));
        }
        return dp[e][f] = minn ; 
        
    }
    int twoEggDrop(int n) {

    int eggs = 2 ; 
        vector<vector<int>> dp(eggs+1,vector<int>(n+1,-1));
       return  solve(eggs , n,dp); 
    }
};