class Solution {
public:
    int majorityElement(vector<int>& nums) {
 // sort(nums.begin(),nums.end()); 
 //        return nums[nums.size()/2]; 
        
        int count = 1 , mm = nums[0]; 
        for(int i= 1; i<nums.size();i++)
        {
            if(count ==0 )
            {
                count++;
                 mm = nums[i]; 
            }
            else if(nums[i]==mm)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        
        
        return mm ; 
    }
};