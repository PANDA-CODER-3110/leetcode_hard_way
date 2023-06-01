class Solution {
public:
    string largestOddNumber(string s) {
        while(!s.empty() && (s.back()-'0')%2==0)
            s.erase(s.end()-1) ; 
        
        return s ; 
    }
};