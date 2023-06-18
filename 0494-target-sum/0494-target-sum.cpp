class Solution {
public:
    int countWays(int i, int s, vector<int> &nums, int n, map<pair<int, int>, int> &dp, int target) {
        if(i == n) {
            return s == target;
        }
        if(dp.find({i, s}) != dp.end()) {
            return dp[{i, s}];
        }
        return dp[{i, s}] = countWays(i+1, s+nums[i], nums, n, dp, target) +
            countWays(i+1, s-nums[i], nums, n, dp, target);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n =  nums.size();
        map<pair<int, int>, int> dp;
        return countWays(0, 0, nums, n, dp, target);
    }
};