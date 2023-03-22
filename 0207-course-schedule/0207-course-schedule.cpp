class Solution {
public:
    bool solve(vector<int>adj[] , vector<int>&vis ,int node , vector<int>&pathvis )
    {
       vis[node] = 1 ; 
        pathvis[node] = 1; 
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(solve(adj,vis,it,pathvis)==true )
                    return true ; 
            }
            else if(pathvis[it])
                return true ; 
        }
        pathvis[node] = 0 ; 
        return false ; 
    }
    bool canFinish(int n, vector<vector<int>>& pr) {
        if(pr.size()==0 ) return true ; 
   vector<int>adj[n+1]; 
      for(int i = 0;i<pr.size();i++){
            int u = pr[i][0];
            int v = pr[i][1];
            adj[u].push_back(v);
        }
        
        vector<int>pathvis(n+1,0); 
    vector<int>vis(n+1,0); 
        for(int i=0 ; i<n;i++)
        {
            if(!vis[i])
            {
                if(solve(adj,vis,i,pathvis)==true )
                    return false ; 
            }
        }
        return true   ; 
        
    }
};