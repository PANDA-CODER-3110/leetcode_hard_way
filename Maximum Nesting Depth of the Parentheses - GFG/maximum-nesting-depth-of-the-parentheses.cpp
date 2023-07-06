//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        int m=0;

        int count=0;

        int n=s.size();

        for(int i=0;i<n;i++){

            if(s[i]=='('){

                count+=1;

            }

            if(s[i]==')'){

                count-=1;

            }

            m=max(count,m);

        }

        return m;
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
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends