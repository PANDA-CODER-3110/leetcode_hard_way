class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
       vector<int> dpleft(nums.size(), 1);
    vector<int> dpright(nums.size(), 1);
    for(int i=1; i<nums.size(); i++) {
        for(int j=0; j<i; j++) {
            if(nums[i]>nums[j]) {
                dpleft[i] = max(dpleft[i], dpleft[j]+1);
            }
        }
    }
        reverse(nums.begin() , nums.end()) ; 
    //coming from right
     for(int i=1; i<nums.size(); i++) {
        for(int j=0; j<i; j++) {
            if(nums[i]>nums[j]) {
                dpright[i] = max(dpright[i], dpright[j]+1);
            }
        }
    }
        reverse(dpright.begin()  , dpright.end()) ; 
    //calculate the longest
    int longest = 0;
    //conside i the middle
    for(int i=0; i<nums.size(); i++) {
        if(dpleft[i]>1 && dpright[i]>1) {
            int ans = dpleft[i]+dpright[i]-1;
            longest = max(longest, ans);
        }
    }
    return nums.size()-longest;
    }
};