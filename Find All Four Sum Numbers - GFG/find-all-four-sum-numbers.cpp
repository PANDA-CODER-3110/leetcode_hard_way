//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int k) {
       vector<vector<int>>ans  ; 
        if(nums.empty()) return  ans ; 
        int n = nums.size( ) ; 
        sort(begin(nums),end(nums)) ; 
        for(int i=0 ; i<n;i++)
        {
            int target_3 = k - nums[i] ; 
            for(int j =i+1 ;j<n;j++)
            {
                int target2 = target_3 - nums[j]  ; 
                int start = j+1 ; 
                int end = n- 1; 
                while(start<end)
                {
                    int sum = nums[start]+nums[end] ; 
                    if(sum>target2)
                    end-- ; 
                    else if(sum<target2)
                    start++ ; 
                    else
                    {
                        vector<int>res ;
                         res.push_back(nums[i]) ; 
                        res.push_back(nums[j]) ;
                        res.push_back(nums[start]) ;
                        res.push_back(nums[end]) ;
                        ans.push_back(res) ; 
                        int lo = nums[start];
                        int hi = nums[end];
                        while (start < end && nums[start] == lo  ) start++;
                    
                        // Processing the duplicates of number 4
                        while (start < end && nums[end] ==hi ) end --;
                        
                    }
                }
                  // Processing the duplicates of number 2
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
             while (i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }
        
        return ans  ; 
        
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends