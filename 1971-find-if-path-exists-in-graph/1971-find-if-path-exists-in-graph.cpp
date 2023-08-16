class Disjoint_set
{
    vector<int> parent, size, rank;

public:
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
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        Disjoint_set ds(n) ; 
        for(auto it : edges)
        {
            if(ds.findupar(it[0]) != ds.findupar(it[1]))
            {
                ds.unionbysize(it[0] , it[1]) ; 
            }
            else
                continue ; 
        }
      return (ds.findupar(src)== ds.findupar(dest)) ;
   
    }
};