//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void solve(vector<vector<int>>&ans ,vector<int>&temp ,vector<int> &A, int B , int ind  )
    {
        if(B==0)
        {
            ans.push_back(temp) ; 
            return  ; 
        }
        for(int i = ind ; i<A.size();i++)
        {
            if(i>ind && A[i]==A[i-1])
            continue ; 
            if(A[i]<=B)
            {
                temp.push_back(A[i]) ; 
                solve(ans , temp ,A , B - A[i], i+1) ; 
                temp.pop_back() ; 
            }
        }
        return ; 
    }
     vector<vector<int>> combinationSum2(vector<int>& A, int B) {
         vector<vector<int>>ans ; 
        vector<int>temp ; 
        sort(A.begin(),A.end()) ; 
        solve(ans , temp , A , B , 0  ) ; 
        return ans ; 
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends