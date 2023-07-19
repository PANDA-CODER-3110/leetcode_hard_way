const long long modVal = 1000000007;

class Solution {
public:
    int sumDistance(vector<int> &nums, string s, int d) {
        // support variables
        int len = nums.size();
        long long res = 0, tot = 0, n;
        vector<long long> ns(len);
        // populating ns
        for (int i = 0; i < len; i++) {
            n = nums[i];
            if (s[i] == 'L') n -= d;
            else n += d;
            ns[i] = n;
        }
        // parsing ns
        sort(begin(ns), end(ns));
        for (int i = 0; i < len; i++) {
            n = ns[i];
            // updating res and tot
            res += i * n - tot;
            if (res >= modVal) res %= modVal;
            tot += n;
        }
        return res;
    }
};