class Solution {
public:
    bool halvesAreAlike(string s) {
        int a = s.size() ; 
        string d = s.substr(0 ,a/2) ; 
        string e = s.substr(a/2 ,a) ;
 long long int l = 0  , m =0   ; 
        for(auto it : e)
        {
           if(it=='a' || it== 'e' || it=='i' || it=='o' || it=='u' ||it=='A' || it== 'E' || it=='I' || it=='O' || it=='U')
               l++  ; 
        }
        for(auto it : d)
        {
            if(it=='a' || it== 'e' || it=='i' || it=='o' || it=='u' ||it=='A' || it== 'E' || it=='I' || it=='O' || it=='U')
               m++  ;  
        }
        return l == m ; 
       
     }
};