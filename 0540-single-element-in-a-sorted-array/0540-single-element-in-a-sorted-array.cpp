class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
          int n = nums.size();
            if(n == 1){
                return nums[0];
            }
            //first element is single
            if(nums[0] != nums[1]){
                return nums[0];
            }
            //last element is single
            if(nums[n-1] != nums[n-2]){
                return nums[n-1];
            }

            int start = 1;
            int end = n-2;

            while(start <= end){
                int mid = start + (end-start)/2;

                if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                    return nums[mid];
                }
                //left half
                if(mid%2==0 && nums[mid]==nums[mid+1] || mid%2==1 && nums[mid]==nums[mid-1]){
                    start = mid + 1;
                }
                //right half
                else{
                    end = mid-1 ;
                }
            }
            return -1;
    }
};