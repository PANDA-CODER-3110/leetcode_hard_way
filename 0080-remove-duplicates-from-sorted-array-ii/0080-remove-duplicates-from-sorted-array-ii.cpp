class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0  , j =0 , ans = 0; 
        while(i<nums.size())
        {
            int temp = nums[i] ; 
             nums[j] = nums[i]  ; 
            ans++ ; 
            int cnt =0 ; 
            while(i<nums.size() && temp == nums[i])
            {
                i++   , cnt ++ ; 
            }
            if(cnt>=2)
            {
                nums[j+1] = nums[j] ; 
                j+=2 ; 
                ans++ ; 
            }
            else
                j++ ; 
        }
        return ans ; 
    }
};