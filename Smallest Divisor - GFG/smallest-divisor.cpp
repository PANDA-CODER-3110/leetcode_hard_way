//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool can(vector<int>& nums, int K, int mid )
  {
      long long int cnt =0 ; 
      for(auto it : nums)
      {
          cnt+=ceil((1.0*it)/mid) ; 
      }
      return cnt<=K ; 
  }
    int smallestDivisor(vector<int>& nums, int K) {
    int start = 1 , end = *max_element(nums.begin() , nums.end()) ; 
    while(start<=end)
    {   int m = (start+end)/2  ;
        if(can(nums,K,m))
        {
            end = m-1 ; 
        }
        else
        start = m+1 ; 
    }
    return start ; 
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends