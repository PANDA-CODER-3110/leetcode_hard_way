class Solution {
public:
   int helper(int n,int target,vector<int>& nums,vector<int>& dp){
        if(target==0){
            return 1;
        }
        if(dp[target]!=(-1)){
            return dp[target];
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=target){
            count+= helper(n,target-nums[i],nums,dp);
            }
        }
        return dp[target]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(target+1,-1);
        dp[0]=1;
        helper(n,target,nums, dp);
        return dp[target];
    }
};