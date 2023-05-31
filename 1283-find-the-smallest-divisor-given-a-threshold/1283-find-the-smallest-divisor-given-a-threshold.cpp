class Solution {
public:
    // Return the sum of division results with 'divisor'.
    int findDivisionSum(vector<int>& nums, int& divisor , int threshold) {
        long long int result = 0;
        for (int& num : nums) {
            result += ceil((1.0 * num) / divisor);
        }
        return result<=threshold;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = -1;
        
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        high++;
        
        // Iterate using binary search on all divisors.
        while (low <=  high) {
            int mid = (low + high) / 2;
            // If current divisor does not exceed threshold, 
            // then it can be our answer, but also try smaller divisors
            // thus change search space to left half.
            if (findDivisionSum(nums, mid,threshold)) 
            {
                high = mid -1 ; 
            }
            // Otherwise, we need a bigger divisor to reduce the result sum
            // thus change search space to right half.
            else {
                low = mid + 1;
            }
        }
        
        return  low ;
    }
};