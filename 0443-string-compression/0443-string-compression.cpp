class Solution {
public:
    int compress(vector<char>& chars) {
         int i = 0;
        int ansindex = 0;
        int n = chars.size();

        while (i < n) {
            int j = i + 1;
            while (j < n && chars[i] == chars[j]) {
                j++;
            }

            chars[ansindex] = chars[i];
            ansindex++;
            int count = j - i;
            if (count > 1) {
                string cnt = to_string(count);
                int k=0;

                while (k < cnt.size()) {
                    chars[ansindex] = cnt[k];
                    k++;
                    ansindex++;
                }
                
            } 
             i=j;
        }

        return ansindex;
    }
};