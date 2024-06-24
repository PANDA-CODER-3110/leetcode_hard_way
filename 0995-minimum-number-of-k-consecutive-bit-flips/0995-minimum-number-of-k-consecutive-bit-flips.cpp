class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
         int n = nums.size();
        int cnt = 0;  // To count the number of flips
        unordered_map<int, int> m;  // To track flips at each position
        int sum = 0;  // To maintain the cumulative flips

        for (int i = 0; i < n; i++) {
            // Add the effect of the flip at the current position
            sum += m[i];

            // If the current sum of flips is odd, it means we have flipped an odd number of times up to this point
            if (sum % 2 == 1) {
                nums[i] = !nums[i];
            }

            // If nums[i] is 0, we need to flip the next k bits starting from this position
            if (nums[i] == 0) {
                // If flipping k bits exceeds the array boundary, return -1
                if (i + k > n) {
                    return -1;
                }
                cnt++;  // Increment the flip count
                m[i]++;  // Increment the flip effect at position i
                m[i + k]--;  // Decrement the flip effect k positions ahead
                sum++;  // Increment the cumulative flips
            }
        }
        return cnt;
    }
};