//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       set<pair<int,int>>st ; 
        vector<int>dist(V, 1e9) ; 
        dist[S] =0 ; 
        st.insert({S,0}) ; 
        while(!st.empty())
        {
            auto it = *st.begin() ; 
            int node = it.first ; 
            int dis = it.second ; 
            st.erase(it) ; 
            for(auto it : adj[node])
            {
                int wt = it[1] ; 
                int ednode = it[0] ; 
                if(dis+wt<dist[ednode])
                {
                    if(dist[ednode]!=1e9)
                    st.erase({ednode , dist[ednode]}) ; 
                    dist[ednode] = dis+wt ; 
                    st.insert({ednode , dist[ednode]}) ; 
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