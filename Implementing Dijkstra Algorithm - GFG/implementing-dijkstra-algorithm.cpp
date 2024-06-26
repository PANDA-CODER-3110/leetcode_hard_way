//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int>dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       set<pair<int , int>>st ; 
        vector<int>dist(V,1e9) ; 
        dist[S] =0 ; 
        st.insert({S , 0}) ; 
        while(!st.empty())
        {
          auto it  = (*st.begin()) ; 
          int node = it .first ; 
          int dis = it.second ; 
          st.erase(it) ; 
           for(auto it : adj[node])
           {
               int adjnode = it[0] ; 
               int edwt = it[1] ; 
               if(dist[node]+edwt<dist[it[0]])
               {
                   if(dist[it[0]]!=1e9)
                   st.erase({adjnode ,dist[adjnode]}) ; 
                   dist[it[0]] = dist[node]+edwt ; 
                   st.insert({adjnode , dist[it[0]]}) ; 
               }
           }
        }
        return dist ; 
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends