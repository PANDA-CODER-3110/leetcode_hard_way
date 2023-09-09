class Solution {
public:
    int missingNumber(vector<int>& nums) {
         long long int ans = accumulate(nums.begin() , nums.end() , 0 ) ; 
        long long int st = (nums.size()*(nums.size()+1))/2 ;
        
        return (int)st - ans ; 
    }
};