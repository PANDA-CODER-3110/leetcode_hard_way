//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
      int start =0 , end =n-1 ; 
      while(start <= end)
      {
          int mid = (start+end)/2 ; 
          if(arr[mid]==arr[mid^1])
                start = mid+1 ; 
                else end = mid -1 ; 
                
          
      }
      return arr[start]  ; 
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends