//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& nums, int target) {
         int left = 0 , right = N-1;
        while(left<=right)
        {
            int m = (left+right)/2;
            if(nums[m]==target)
            return true ; 
            if(nums[left]==nums[m] && nums[right]==nums[m])
            {
                left++;
                right--; 
            }
        else if (nums[left]<=nums[m])
        {
            if(nums[left]<=target && target<=nums[m])
            {
                right=m-1;
            }
            else
            {
                left=m+1;
            }

        }
        else
        {
            if(nums[right]>=target && target>=nums[m])
            {
                left=m+1;
            }
            else
            {
                right=m-1;
            }
        }
        }
        return false ; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends