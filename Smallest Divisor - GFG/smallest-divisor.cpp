//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int findDivisionSum(vector<int>& nums, int& divisor , int threshold) {
        long long int result = 0;
        for (int& num : nums) {
            result += ceil((1.0 * num) / divisor);
        }
        return result<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int K) {

         int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        // Iterate using binary search on all divisors.
        while (low <=  high) {
            int mid = (low + high) / 2;
            // If current divisor does not exceed threshold, 
            // then it can be our answer, but also try smaller divisors
            // thus change search space to left half.
            if (findDivisionSum(nums, mid,K)) 
            {
                high = mid -1 ; 
            }
            // Otherwise, we need a bigger divisor to reduce the result sum
            // thus change search space to right half.
            else {
                low = mid + 1;
            }
        }
        
        return  low ;
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