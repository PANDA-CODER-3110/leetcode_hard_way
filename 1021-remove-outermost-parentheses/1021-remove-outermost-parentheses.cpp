class Solution {
public:
    string removeOuterParentheses(string s) {
        int sum =0 ; 
        string ans ="" ; 
        for(int i=0 ; i<s.size();i++)
        {
            if(s[i]==')')
                sum -- ; 
            else 
                sum++ ; 
            if(sum == 1 && s[i]=='(')
                continue ; 
            else if (sum == 0  && s[i]==')')
                continue ; 
            else ans+=s[i] ; 
        }
        
        return ans ; 
    }
};