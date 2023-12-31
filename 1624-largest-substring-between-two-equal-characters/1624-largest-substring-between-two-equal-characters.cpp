class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
          int n = s.size();
        vector<int> lastIndex(26, -1);
        int maxi = -1;

        for (int i = 0; i < n; ++i) {
            if (lastIndex[s[i] - 'a'] != -1) {
                int temp = i - lastIndex[s[i] - 'a'] - 1;
                maxi = max(maxi, temp);
            } else {
                lastIndex[s[i] - 'a'] = i;
            }
        }

        return maxi;
    }
};