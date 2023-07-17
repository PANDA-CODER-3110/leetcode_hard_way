class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>mp1(26,0) ; 
        for(auto it : magazine)
        {
            mp1[it-'a']++ ; 
        }
        for(auto it : ransomNote)
        {
            if(mp1[it-'a']==0)
                return false; 
            else
                mp1[it-'a'] -- ; 
                
        }
        return true ; 
    }
};