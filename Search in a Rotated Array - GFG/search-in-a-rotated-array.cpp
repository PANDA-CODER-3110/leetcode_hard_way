//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int A[], int l, int h, int key){
      while(l<=h)
      {
          int m = (l+h)/2; 
          if(A[m]==key) return m ;  
          else if(A[l]<=A[m])
          {
              if(A[l]<=key && key<=A[m])
              {
                  h = m-1 ; 
              }
              else
              l= m+1  ; 
          }
          else
          {
              if(A[m]<=key && key<=A[h])
              {
                  l = m+1 ; 
              }
              else
             h = m-1 ; 
          }
      }
      return - 1; 
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