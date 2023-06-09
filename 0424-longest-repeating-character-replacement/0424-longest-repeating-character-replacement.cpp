class Solution {
public:
    int characterReplacement(string S, int k) {
         int n = S.size();
        vector<int> mp(26, 0);
        int head = 0;
        int tail = 0;
        int res = 0;
        
        for(int head = 0; head < n; head++) {
            mp[S[head] - 'A']++;
            
            while((head - tail + 1) - *max_element(mp.begin(), mp.end()) > k) {
                mp[S[tail] - 'A']--;
                tail++;
            }
            
            res = max(res, (head - tail + 1));
        }
        
        return res;
    }
};