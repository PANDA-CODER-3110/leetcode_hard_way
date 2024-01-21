class Solution {
public:

    int solve(vector<int>&nums,int pos,int n ,vector<int>&dp)
    {
        if(pos>n)
            return 0 ;
        
        if(dp[pos]!=-1)  return dp[pos]; 
        int op1 = nums[pos]+solve(nums,pos+2,n,dp);
        int op2  = solve(nums,pos+1,n,dp); 
        return dp[pos] = max(op1,op2);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,0,nums.size()-1,dp);
        
        dp[0] = nums[0];
        dp[1] =  nums[1] ;
        for(int i=2 ; i<nums.size();i++)
        {
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }
        
        return dp[nums.size()-1]  ;
        
    }
};