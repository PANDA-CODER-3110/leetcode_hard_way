class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
      int ans=1;
        int i=0;
        int j=1;
        int n=s.size();
        bool found=false;
        int ind=-1;
        while(j<n){
            if(s[j]==s[j-1]){
                if(!found){
                    found=true;
                    ind=j;
                 }
                else{
                    i=ind;
                   ind=j;   
           }           
    }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};