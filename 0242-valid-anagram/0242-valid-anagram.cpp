class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26]={0}  ; 
        if(s.size()!=t.size()) return false ; 
        for(int i=0 ; i<s.size();i++)
        {
            a[s[i]-'a']++ ; 
        }
        for(int i=0 ; i<t.size();i++)
        {
            if(a[t[i]-'a']==0)
                return false ; 
            else
                a[t[i]-'a']-- ; 
        }
        
       
        return true ; 
    }
};