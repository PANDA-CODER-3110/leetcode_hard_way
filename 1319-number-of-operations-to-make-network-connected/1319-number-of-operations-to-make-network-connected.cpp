class DisjointSet{
       
    public: 
     vector<int>rank , parent , size ; 
    DisjointSet(int n )
    {
        rank.resize(n , 0) ; 
        parent.resize(n , 0)  ; 
        for(int i=0 ; i<n;i++){
            parent[i] = i  ; 
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
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n) ; 
       int cnt=0; 
        for(auto it : connections){
            if(ds.find(it[0])==ds.find(it[1]))
                cnt++ ; 
            else
                ds.union_by_size(it[0] , it[1]) ; 
        }
        int ans =0 ; 
        for(int i=0 ;i<n;i++){
            if(ds.parent[i]==i)
                ans++ ; 
        }
        
      if(cnt>=ans-1)
          return ans -1 ; 
        return -1 ; 
    }
};