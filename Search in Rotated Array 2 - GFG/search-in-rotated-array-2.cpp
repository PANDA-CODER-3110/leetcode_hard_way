//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& A, int Key) {
        int l = 0 , h = A.size() -1 ; 
        int key = Key ; 
         while(l<=h)
      {
          int m = (l+h)/2; 
          if(A[m]==key) return true ;  
          if(A[l]==A[m] && A[h]==A[m])
          {
              l++ ; 
              h-- ; 
          }
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