//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        int sum =0 ; 
        string ans = "" ; 
        for(int i=0 ; i<s.size();i++)
        {
            if(s[i]==')')
            sum-- ; 
            else 
            sum++ ;
            if(sum==1 && s[i]=='(')
            continue ; 
            else if(sum==0 && s[i]==')')
            continue ; 
            else ans+=s[i] ;
        }
        return ans ; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends