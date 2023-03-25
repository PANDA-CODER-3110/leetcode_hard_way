class Solution {
public:
      typedef long long ll;
    void dfs(vector<int>&vis,unordered_map<int,vector<int>>& m,int idx , long long int&cnt  )
    {
        vis[idx]= 1; 
        cnt ++; 
        for(auto it : m[idx])
        {
            if(!vis[it])
            {
                dfs(vis,m,it,cnt); 
            }
        }
        
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>adj[n]; 
        unordered_map<int,vector<int>> m; // making adjacency list
        for(int i=0;i<edges.size();i++){
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
     
      ll p = ((ll)n*(n-1))/2;
        
        vector<int>vis(n+1,0); 
        for(int i=0 ; i<n;i++)
        {
            if(!vis[i])
            {   long long int cnt =0 ; 
                dfs(vis,m,i,cnt);
                   p-=((cnt)*(cnt-1))/2; 
                    
            }
        }
        return p; 
    }
};