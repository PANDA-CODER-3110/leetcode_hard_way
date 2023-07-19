class Solution {
public:
    string smallestString(string s) {
      int i=0;
        while(s[i]=='a'&& i<s.size()){
            i++;
        }
        if(i==s.size()){
            s[i-1] = 'z';
        }
        while(s[i]!='a' && i<s.size()){
            s[i]=s[i]-1;
            i++;
        }
        return s;   
    }
};