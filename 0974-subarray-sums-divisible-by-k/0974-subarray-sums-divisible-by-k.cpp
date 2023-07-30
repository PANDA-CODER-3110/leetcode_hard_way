class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
  unordered_map<int , int>mp ; 
        mp[0]++ ; 
        long long int ans =0 , sum =0 ; 
        for(int i = 0 ; i<nums.size();i++){
            sum+=nums[i] ; 
            sum = (sum%k + k)%k ; 
            if(mp.find(sum)!=mp.end())
                ans+=mp[sum]  ;
            mp[sum]++ ; 
        }
        
        return ans  ; 
        
    }
};