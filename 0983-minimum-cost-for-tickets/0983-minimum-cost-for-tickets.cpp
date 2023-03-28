class Solution {
public:
    
  //   int n;
  
int solve(vector<int>&days,vector<int>&costs,int index,vector<int>&dp)
{      int  n = days.size();
    if(index >= n) return 0 ; 
 if(dp[index]!=-1) return dp[index];
  
int costd = costs[0] + solve(days , costs , index+1,dp);

    
     int i;
        for(i = index ; i<n and days[i]<days[index]+7 ; i++);   
        int costw = costs[1] + solve(days, costs, i,dp); 
    
    for(i = index ; i<n and days[i]<days[index]+30;i++);
    int costm = costs[2]+solve(days,costs,i,dp); 

    
     return dp[index] = min({costd,costw,costm});
    
    
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int>Days(days.begin(),days.end());
        vector<int>dp(500);
   for(int i=1 ; i<366;i++)
   {
       dp[i]= dp[i-1]; 
       if(Days.find(i)!=Days.end())
       dp[i]  = min({
                        dp[i-1]+costs[0],
                        dp[max(0,i-7)]+costs[1],
                        dp[max(0,i-30)]+costs[2]    
                    });
   }
        return dp[365];
    }
};