class Solution {
public:
    string minWindow(string s, string t) {
       if(t.length() > s.length()) return "";
        if(s == t) return s;
        
        int i=0, j =0, minLen =INT_MAX, start =-1, cnt =0;
        
        vector<int> mpp(256,0);
        for(auto ch: t){ 
            if(mpp[ch-'A'] == 0) cnt++;
            mpp[ch-'A']++;
        }

        while(j<s.length()){
            mpp[s[j] -'A']--;
            if(mpp[s[j] -'A'] == 0) cnt--;

            if(cnt == 0){       
                while(cnt == 0){
                    if(j-i+1 < minLen){                     
                        start= i;
                        minLen= j-i+1;
                    }
                    mpp[s[i]-'A']++;
                    if(mpp[s[i] -'A'] == 1) cnt++;
                    i++;
                }
            }
            j++;
        }

        if(minLen == INT_MAX) return "";
        else return s.substr(start,minLen);
    }
    
};