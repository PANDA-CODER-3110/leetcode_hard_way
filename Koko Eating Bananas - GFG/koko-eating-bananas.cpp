//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool can(int n, int h, int speed, vector<int>&piles){
       long long  int cnt=0;
        for (int i=0; i<n; i++){
            cnt+= (piles[i]/speed)+(piles[i]%speed!=0);
           
        }
        return (cnt<=h);
    }
    int Solve(int N, vector<int>& piles, int H) {
         sort(piles.begin(),piles.end());
      int start=1; int end= 1e9;
        while(start<=end)
        {
            int m = (start+end)/2; 
            if(can(N,H,m,piles))
            {
                end= m -1  ; 
            }
            else
            {
                start = m+1 ; 
            }
        }
        return start; 
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
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends