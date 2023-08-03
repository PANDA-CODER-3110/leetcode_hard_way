class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ; 
        vector<int>dp(nums.size() , 1) , hash(nums.size()) ; 
        int n = nums.size() ; 
        int maxi = 0 , lastind =0 ; 
        
        for(int i =0 ; i<n ; i++){
            hash[i] = i ; 
            for(int j =0 ; j<i  ;j++){
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    dp[i] = 1+ dp[j] ; 
                    hash[i] = j ; 
                }
            }
            if(maxi <dp[i]){
                maxi = dp[i] ; 
                lastind = i  ; 
            }
        }
        vector<int>ans ; 
        ans.push_back(nums[lastind]) ; 
        while(hash[lastind]!=lastind){
            lastind = hash[lastind] ; 
            ans.push_back(nums[lastind]) ; 
        }
        reverse(ans.begin() , ans.end()) ;
        return ans ; 
        
    }
};