//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int ac =0 , bc =0;
    int i = 1 ;
    while(i < str.size())
    {
        if(str[i-1] == str[i])
        {
            i++;
            continue;
        }
        else if(str[i] == 'a' && str[i-1] == 'b')
        {
            bc++;
        }
        else if(str[i] == 'b' && str[i-1] == 'a')
        {
            ac++;
        }
        i++;
    }
    return max(ac,bc)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends