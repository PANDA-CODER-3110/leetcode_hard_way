//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
       reverse(s.begin(),s.end()) ; 
       string ans = "" ; 
        string temp ="" ; 
        for(int i=0 ; i<s.size();i++)
        {
            if(s[i]!='.')
            {
                temp+=s[i] ; 
            }
            else
            {
                reverse(temp.begin(),temp.end()) ; 
                ans+=temp ; 
                ans+="." ; 
                temp="" ; 
            }
        }
        reverse(temp.begin(),temp.end()) ; 
                ans+=temp ; 
        return ans ; 
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends