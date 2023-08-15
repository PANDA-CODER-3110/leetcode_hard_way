class Disjoint_set{
 
    public:
      vector<int>parent , size , rank ; 
    Disjoint_set(int n )
    {
        parent.resize(n+1 , 0) ;
        rank.resize(n+1 ,0) ;
        size.resize(n+1  , 0) ;
        for(int i =0 ; i<n;i++)
        {
            parent[i] = i; 
            size[i] =1 ; 
        }
        
    }
    int findpar(int node)
    {
        if(node == parent[node])
            return node ; 
       return  parent[node] = findpar(parent[node]) ; 
    }
    void unionbysize(int u , int v)
    {
        int uu = findpar(u)  ; 
        int uv = findpar(v)  ; 
        if(uu == uv )
            return ; 
        if(size[uu]<size[uv])
        {
            size[uv]+=size[uu] ; 
            parent[uu] = uv ; 
         }
        else
        {
          size[uu]+=size[uv] ; 
            parent[uv] = uu ;    
        }
    }
        
} ;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjoint_set ds(n) ; 
        int maxi = 0  ; 
       for(auto it : connections)
       {
           if(ds.findpar(it[0])==ds.findpar(it[1]))
               maxi++ ; 
           else
              ds.unionbysize(it[0] , it[1]) ;        
       }
        
        int cnt =0 ; 
        for(int i =0 ; i<n  ;i++)
        {
            if(ds.parent[i]==i)
                cnt++ ; 
        }
        cnt-- ; 
        return maxi>=cnt?cnt:-1 ; 
    }
};