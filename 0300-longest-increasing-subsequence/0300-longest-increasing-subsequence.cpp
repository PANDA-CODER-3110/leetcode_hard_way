class Solution {
public:
    int solve(vector<int>& nums, int ind , int prev , vector<vector<int>>&dp)
    {
        if(ind ==nums.size()){
            return 0  ;
        }
        if(dp[ind][prev+1]!=-1)
            return dp[ind][prev+1] ; 
        int len = 0+ solve(nums , ind+1 , prev , dp) ; 
        if(prev==-1 || nums[ind]>nums[prev])
            len = max(len , 1+solve(nums , ind +1 , ind , dp ) );
        
        return dp[ind][prev+1] =  len  ; 
    }
    int lengthOfLIS(vector<int>& nums) {
      //  vector<vector<int>>dp(nums.size()+1 , vector<int>(nums.size()+1 , 0)) ; 
   // return solve(nums  , 0 , -1 , dp) ; 
        int maxi =0 ; 
            vector<int>dp(nums.size(), 1) ;
        int n = nums.size()  ; 
        for(int i =0 ; i<n;i++){
            for(int j = 0 ; j<i ; j++){
                if(nums[i]>nums[j])
                    dp[i] = max(dp[i] , 1+dp[j]) ; 
            }
            maxi = max(maxi , dp[i]) ; 
        }
        
        return maxi  ; 
    }
};