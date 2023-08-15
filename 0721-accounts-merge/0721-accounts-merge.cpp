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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n  =  accounts.size() ; 
        Disjoint_set ds(n) ; 
        unordered_map<string , int>mp ; 
        for(int i =0 ; i<n;i++)
        {
            for(int j =1 ; j<accounts[i].size() ;j++)
            {
                string mail = accounts[i][j] ; 
                if(mp.find(mail)==mp.end())
                {
                    mp[mail] = i ; 
                }
                else
                {
                    ds.unionbysize(i , mp[mail]) ; 
                }
            }
        }
        
        vector<string>merge[n] ; 
        for(auto it : mp)
        {
            string mail = it.first  ; 
            int node = ds.findupar(it.second) ; 
            merge[node].push_back(mail) ; 
            
            
        }
        vector<vector<string>>ans ; 
        
        for(int i =0 ; i<n ; i++)
        {
            if(merge[i].size()==0)
                continue ; 
            sort(merge[i].begin() , merge[i].end()) ; 
            vector<string>temp ; 
            temp.push_back(accounts[i][0]) ; 
            for(auto it : merge[i])
            {
                temp.push_back(it) ; 
            }
            ans.push_back(temp) ; 
        }
        
        return ans  ; 
        
    }
};