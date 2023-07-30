class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans ; 
        for(int i =0 ;i<nums.size();i++){
            int pos = abs(nums[i]) -1 ; 
            if(nums[pos]<0)ans.push_back(pos+1) ; 
            nums[pos] = -nums[pos] ; 
        }
        return ans ; 
    }
};