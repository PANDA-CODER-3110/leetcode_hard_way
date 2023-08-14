//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
       set<pair<int , int>>st ; 
        st.insert({0 , start}) ; 
        vector<int>dist(100000 , 1e9) ; 
        dist[start] = 0 ; 
        int mod = 100000 ; 
        if(start == end)  return 0 ; 
        while(st.size())
        {
            auto pl = (*st.begin()) ; 
            int node = pl.second ; 
            int steps = pl.first ; 
           st.erase(pl) ; 
             if(node == end)
                    return dist[node]  ; 
            for(auto it : arr)
            {
                int num = (it*node)%mod ; 
                if(steps+1<dist[num])
                {
                    st.erase({dist[num]  , num}) ; 
                    dist[num] = steps+1 ; 
                  st.insert({ dist[num] , num }) ; 
                   
                }
            }
        }
        
        return -1 ; 
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends