class dis
{
    public:
    vector<int>par , size  ; 
    dis(int n )
    {
        par.resize(n , 0) ;
        size.resize(n, 0) ; 
        for(int i =0 ; i<n  ;i++)
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
    int dir[5] = {-1 , 0, 1,0,-1}  ; 
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        dis ds(n*n) ; 
        for(int i =0 ; i<n ; i++)
        {
            for(int j =0 ; j<n;j++)
            {
                if(grid[i][j]==0)
                    continue ; 
                for(int k =0 ; k<4 ; k++)
                {
                    int ni = i+dir[k] ; 
                    int nj = j+ dir[k+1] ;
                    if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==1)
                    {
                        int nodeno = (n*i)+j ; 
                        int adj = (n*ni)+nj ; 
                        ds.unionbysize(nodeno , adj) ; 
                    }
                }
            }
        }
        int maxi =0 ; 
        for(int i =0 ; i<n  ; i++)
        {
            for(int j =0 ;j<n ; j++)
            {
                if(grid[i][j]==1)
                    continue ; 
                
                    set<int>st ; 
                    for(int k =0 ; k<4 ; k++)
                    {
                    int ni = i+dir[k ] ; 
                    int nj = j+ dir[k+1] ;
                        if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==1)
                        {
                            st.insert(ds.find(ni*n+nj)) ; 
                        }
                
                    }
                    
                    int total  =0 ; 
                    for(auto it : st)
                    {
                        total +=ds.size[it] ; 
                    }
                    maxi = max(maxi , total+1) ; 
                 
            }
        }
        
        for(int i =0 ;i<n*n ; i++)
        {
            maxi = max(maxi , ds.size[ds.find(i)]) ; 
        }
        
        
        return maxi ; 
        
        
    }
};