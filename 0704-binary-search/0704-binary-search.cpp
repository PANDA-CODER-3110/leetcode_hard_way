class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start =-1 , end = nums.size() ; 
        while(start+1<end)
        {
            int mid = (start+end)/2 ; 
            if(nums[mid]== target) return mid ; 
            else if(nums[mid]<target) start = mid ; 
            else end = mid ; 
        }
        
         return -1 ; 
    }
};