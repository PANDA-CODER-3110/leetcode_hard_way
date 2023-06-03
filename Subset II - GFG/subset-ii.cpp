//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
   void solve(vector<int>& nums , int id , set<vector<int>>&st, vector<int>&ps  )
    {
        if(id == nums.size())
        {
            st.insert(ps); 
            return ; 
        }
        ps.push_back(nums[id]); 
        solve(nums , id+1 , st, ps );
        ps.pop_back(); 
         solve(nums , id+1 , st, ps );
    }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        vector<vector<int>>ans ; 
        vector<int>ps ; 
        sort(nums.begin(),nums.end()); 
        set<vector<int>>st ; 
        solve(nums , 0 , st , ps);
        for(auto it : st )
        {
            ans.push_back(it); 
        }
        return ans ; 
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends