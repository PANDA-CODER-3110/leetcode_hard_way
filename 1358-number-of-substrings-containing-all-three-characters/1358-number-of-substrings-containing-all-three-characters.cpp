class Solution {
public:
     int numberOfSubstrings(string s) {
        int last[3] = {-1, -1, -1}, res = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
            res += 1 + min({last[0], last[1], last[2]});
        }
        return res;
    }
};