class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<char>freq(256,0);        
        int n = s.length(), st = 0, end = 0, ans = 0;		
        while(end < n){            
            freq[s[end]]++;            
            while(freq[s[end]] != 1){
                freq[s[st]]--;
                st++;
            }            
            ans = max(ans, end - st + 1);
            end++;                   
        }        
        return ans;  
    }
};