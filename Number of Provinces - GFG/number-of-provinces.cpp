//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int n) {
        vector<int>gp[n] ; 
        for(int i=0 ;i<n;i++)
        {
            for(int j =0 ; j<n;j++)
            {
                if(adj[i][j]==1)
                {
                    gp[i].push_back(j) ;
                }

            }
        }
        
        
    int cnt = 0 ; 
    vector<int>vis(n , 0) ; 
    queue<int>q ; 
    
    
    for(int i=0 ; i<n;i++)
    {
        if(!vis[i])
        {
             q.push(i) ; 
           cnt++ ; 
           vis[i] =1 ; 
        while(!q.empty())
        {
            int node = q.front() ; 
            q.pop() ; 
         
            for(auto it : gp[node])
            {
                
                if(!vis[it])
                {
                    q.push(it) ; 
                    vis[it] =1 ; 
                }
            }
            
            
        }
        
       
        }
     
        
        
    }
    return cnt ; 
        
        
        
    }
//     int n = grid.size();
// 		vector<int> vis(n, 0);
// 		vector<int> adj[n];

// 		// conversion of matrix into adjacent list.
// 		for (int i = 0; i < n; i++) {
// 			for (int j = 0; j < n; j++)  {
// 				if (grid[i][j] == 1) {
// 					adj[i].push_back(j);
// 				}
// 			}
// 		}

// 		int cnt = 0;
// 		queue<int> q;

// 		for (int i = 0; i < n; i++) {
// 			if (!vis[i]) {
// 				cnt++;         // No. of times the bfs gets called.
// 				q.push(i);
// 				vis[i] = 1;
// 				while (!q.empty()) {
// 					int node = q.front();
// 					q.pop();
// 					for (auto it : adj[node]) {
// 						if (!vis[it]) {
// 							vis[it] = 1;
// 							q.push(it);
// 						}
// 					}
// 				}
// 			}
// 		}

// 		return cnt;
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends