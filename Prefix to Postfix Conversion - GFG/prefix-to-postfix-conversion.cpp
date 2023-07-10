//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string s) {
        reverse(s.begin(),s.end()) ; 
        stack<string>st  ; 
        for(auto it :s)
        {
            if(isalnum(it))
            {
                string temp = "" ; 
                temp+=it ; 
                st.push(temp) ; 
            }
            else{
                string a = st.top() ; 
                st.pop() ; 
                string b = st.top(); st.pop() ;
                 st.push(it+b+a) ; 
            }
        }
        string ans = st.top(); 
        reverse(ans.begin(),ans.end()) ; 
        return   ans; 
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends