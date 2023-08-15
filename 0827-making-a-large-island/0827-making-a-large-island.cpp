class dis
{

public:
    
    vector<int> par, size, rank;
    dis(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 0);
        par.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
            size[i] = 1;
        }
    }

    int find(int node)
    {
        if (node == par[node])
            return node;
        return par[node] = find(par[node]);
    }
    
    void unionbysize(int u, int v)
    {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            par[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            par[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
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