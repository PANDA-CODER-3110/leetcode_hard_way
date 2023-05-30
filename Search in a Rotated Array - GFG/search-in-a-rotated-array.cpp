//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int nums[], int lo, int hi, int target){
     
         while(lo<=hi)
         {  int m  =(lo+hi)/2;
             if(nums[m]==target)
             return m;
           if(nums[lo]<=nums[m])  
            {
                if(nums[lo]<=target &&  nums[m]>=target)
                {
                    hi = m-1;
                }
                else
                lo = m+1;
            }
            else{
            if(nums[m]<=target && nums[hi]>=target)
            {
                lo = m+1;

            }
            else
            {
                hi = m-1;
            }
            }
         }
   
        return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends