class Solution {
public:
    int solve(string&colors , vector<int>&t ,int pos, char prevc , int prevt ,vector<int>&dp )
    {
        if(pos < 0 )
            return 0  ; 
        if(dp[pos]!=-1) return dp[pos]; 
        
        if(colors[pos]==prevc)
            return dp[pos]=solve(colors,t, pos-1,colors[pos],max(prevt,t[pos]),dp)+min(prevt,t[pos] ); 
        else
            return dp[pos]=solve(colors , t , pos-1,colors[pos],t[pos],dp);
        
    }
    int minCost(string colors, vector<int>&time) {
        int  n =  colors.size(); 
        vector<int>dp(n+1,0);
        char prevc = 'A';
        int prevt =0 ; 
       // return solve(colors ,time, n-1, 'A', time[n-1],dp ); 
        for(int i=1 ; i<=n;i++)
        {
            if(colors[i-1]==prevc) 
            {    dp[i] = dp[i-1]+min(prevt,time[i-1]); 
            prevt = max(prevt,time[i-1]);      
            }
            else
            {
                dp[i] = dp[i-1]; 
                prevc = colors[i-1]; 
                prevt = time[i-1]; 
                
            }
        }
        
        return dp[n] ; 
    }
};