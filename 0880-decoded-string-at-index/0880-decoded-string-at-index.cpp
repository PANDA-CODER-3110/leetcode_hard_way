class Solution {
public:
    string decodeAtIndex(string s, int k) {
         long long size = 0;
        string ans = "";
        for (auto &c : s) size = isdigit(c) ? size * (c - '0') : ++size;
        for (int i = s.size() - 1; i >= 0; --i){
            k %= size;
            if (isalpha(s[i]) && !k) return ans += s[i];
            if (isdigit(s[i])) size /= s[i] - '0';
            else --size;
        }
        return ans;
    } 
};