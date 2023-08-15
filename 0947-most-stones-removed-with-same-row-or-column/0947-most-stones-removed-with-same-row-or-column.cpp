class dis
{
    public:
    vector<int>par , size  ; 
    dis(int n )
    {
        par.resize(n+1 , 0) ;
        size.resize(n+1, 0) ; 
        for(int i =0 ; i<=n  ;i++)
        {
            par[i]  = i ; 
            size[i] = 1; 
        }
        
    }
    
    int find(int u )
    {
        if(par[u]==u)
            return  u ; 
        return par[u] = find(par[u]) ; 
    }
    void unionbysize(int u , int v )
    {
        int uu = find(u) ; 
        int uv = find(v) ; 
        if(uu==uv)
            return ; 
        if(size[uu]<size[uv])
        {
            size[uv]+=size[uu] ; 
            par[uu] = uv ; 
        }
        else
        {
             size[uu]+=size[uv] ; 
            par[uv] = uu ; 
        }
    }
}; 
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int  n = stones.size() ;  
        int maxr = 0 ; 
        int maxc =0 ; 
        for(auto it : stones )
        {
            maxr = max(maxr , it[0]) ; 
            maxc = max(maxc , it[1]) ; 
        }
        dis ds(maxr +maxc+1 ) ; 
        unordered_map<int , int>mp ; 
        for(auto it :stones)
        {
            int row = it[0] ; 
            int col = it[1]+maxr +1 ; 
            ds.unionbysize(row ,col) ; 
            mp[row] =1 ; 
            mp[col] =1 ;  
        }
        int cnt =0 ; 
        for(auto it : mp)
        {
            if(ds.find(it.first)==it.first)
                cnt++ ; 
        }
        return n - cnt ; 
        
    }
};