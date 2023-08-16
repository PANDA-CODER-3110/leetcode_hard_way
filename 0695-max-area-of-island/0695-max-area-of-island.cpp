class Disjoint_set
{
    
public:
    vector<int> parent, size, rank;

    Disjoint_set(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findupar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findupar(parent[node]);
    }
    void unionbyrank(int u, int v)
    {
        int ulp_u = findupar(u);
        int ulp_v = findupar(v);
        if (ulp_u == ulp_v)
        {
            return;
        }
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionbysize(int u, int v)
    {
        int ulp_u = findupar(u);
        int ulp_v = findupar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int dir[5] = {-1 , 0 , 1, 0, -1} ; 
    int maxAreaOfIsland(vector<vector<int>>& grid) {
     int n = grid.size() ; 
        int m = grid[0].size() ; 
        cout<<n<<" " <<m ; 
        Disjoint_set ds(n*m) ; 
        for(int i =0 ; i<n;i++)
        {
            for(int  j=0 ; j<m ; j++)
            {
                if(grid[i][j]==0)
                    continue ; 
                int node = (i*m) + j ; 
                for(int k =0 ; k<4 ; k++)
                {
                    int ni = i + dir[k] ; 
                    int nj = j + dir[k+1] ; 
                    if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==1)
                    {
                        int nnode = (m*ni) + nj ;  
                        ds.unionbysize(node , nnode) ; 
                        cout<<node<<" "<<nnode<<endl; 
                    }
                    
                }
            }
        }
        int maxi = 0 ; 
        for(int i =0 ; i<n  ; i++)
        {
          for(int j =0 ; j<m;j++)
          {
              if(grid[i][j]==1)
              {
                  maxi = max(maxi , ds.size[i*m +j]) ; 
              }
          }
        }
        return maxi ; 
        
    }
};