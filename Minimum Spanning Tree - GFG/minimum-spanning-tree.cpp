//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int>rank , parent , size ; 
    public: 
    DisjointSet(int n )
    {
        rank.resize(n+1 , 0) ; 
        parent.resize(n+1 , 0) , size.resize(n+1 , 0) ; 
        for(int i=0 ; i<=n;i++){
            parent[i] = i  ; 
            size[i] =i ; 
        }
    }
    int find(int node)
    {
        if(node==parent[node])
        return node ; 
        return parent[node] = find(parent[node]) ;
    }
    void union_by_size(int u ,int v ){
        int ul_u = find(u) ; 
        int ul_v = find(v) ;
        if(ul_u==ul_v)
        return ; 
        if(rank[ul_u]<rank[ul_v]){
            parent[ul_u] = ul_v ;  
        }
        else if(rank[ul_u]>rank[ul_v])
        parent[ul_v] = ul_u ; 
        else
        {
            parent[ul_v] = ul_u ; 
            rank[ul_u]++ ; 
        }
        
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int , pair<int, int>>>edges ; 
        for(int i =0 ; i<V;i++){
            for(auto it :adj[i])
            {
                edges.push_back({it[1],{i , it[0]}}) ; 
            }
        }
        DisjointSet ds(V) ; 
        sort(edges.begin() , edges.end()) ; 
        int mstwt ; 
        for(auto it : edges){
            int wt = it.first ; 
            int u = it.second . first ; 
            int v = it.second . second ; 
            if(ds.find(u)!=ds.find(v)){
                mstwt+=wt ; 
                ds.union_by_size(u,v) ; 
            }
        }
        return mstwt ; 
        
        
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends