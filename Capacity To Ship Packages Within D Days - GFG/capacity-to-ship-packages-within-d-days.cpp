//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool can(int arr[], int N, int D ,int m )
  {
      int sum =0 ,  cnt =1 ; 
      for(int i=0 ; i<N;i++)
      {
          sum+=arr[i] ; 
          if(sum>m)
          {
              cnt++ ; 
              sum = arr[i] ; 
          }
      }
      return cnt<=D ; 
  }
    int leastWeightCapacity(int arr[], int N, int D) {
       int start = *max_element(arr,arr+N) ; 
       int end = accumulate(arr,arr+N,0) ; 
       while(start<=end)
       {
           int m = (start+end)/2 ;
            if(can(arr,N,D,m)){
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
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends