class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
int lo = 0, hi = nums.size(); // we might need to inseart at the end
    while(lo < hi) { // breaks if lo == hi
        int mid = lo + floor((hi-lo)/2); // always gives the lower mid
        if (target > nums[mid]) {
            lo = mid + 1  ; // no way mid is a valid option
        } else {
            hi = mid  ;// it might be possibe to inseart @ mid
        }
    }
    return hi;
    }
};