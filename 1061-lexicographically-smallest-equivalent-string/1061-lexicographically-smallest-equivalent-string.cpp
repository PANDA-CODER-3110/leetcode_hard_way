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
        if (ulp_u < ulp_v)
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
              parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        Disjoint_set ds(26) ; 
        for(int  i =0 ; i<s1.size();i++)
        {
            int a = s1[i] - 'a' ; 
            int b = s2[i] - 'a' ; 
            ds.unionbysize(a , b) ; 
        }
        
        for(int i =0 ; i<baseStr.size() ; i++)
        {
            baseStr[i] = ds.findupar((baseStr[i] - 'a')) + 'a' ; 
        }
         
        return baseStr ; 
    }
};