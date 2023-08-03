class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
     int maxi =0  , lastind =0 ; 
        int n = nums.size() ; 
        vector<int>dp(n , 1) , hash(n) ; 
        for(int i =0 ; i<n;i++){
            hash[i] =i ; 
            for(int j = 0 ; j<i;j++){
                if(nums[i]>nums[j] && dp[i]<1+dp[j]){
                    dp[i] = 1+dp[j] ; 
                    hash[i] = j ; 
                }
            }
            if(dp[i]>maxi)
            {
                maxi  = dp[i] ; 
                lastind = i ; 
            }
        }
        vector<int>ans ; 
        ans.push_back(nums[lastind]) ; 
        while(hash[lastind]!=lastind){
            lastind = hash[lastind] ; 
            ans.push_back(nums[lastind]) ; 
         }
        reverse(ans.begin() , ans.end() ) ; 
        
        for(auto it: ans)
            cout<<it<<" " ; 
         return maxi ; 
    }
};