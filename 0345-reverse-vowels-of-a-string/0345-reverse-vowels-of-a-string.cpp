class Solution {
public:
     bool isVowel(char chr)
    {
        return (chr == 'a' || chr == 'e' || chr == 'i' || chr == 'o' || chr == 'u' || chr == 'A' || chr == 'E' || chr == 'I' || chr == 'O' || chr == 'U');
    }
    string reverseVowels(string s) {
        int lastPos = -1;
        int l = 0;
        int r = s.size() - 1;
        bool lc, rc;
        while (l < r) {
            lc = isVowel((char)s[l]);
            rc = isVowel((char)s[r]);
            if (lc && rc) {
                swap(s[l], s[r]);
                l++;
                r--;
            } else if (lc && !rc){r--;} else if (!lc && rc) {l++;} else if (!lc && !rc) {
                l++;
                r--;
            }
        }
        return s;
    }
};