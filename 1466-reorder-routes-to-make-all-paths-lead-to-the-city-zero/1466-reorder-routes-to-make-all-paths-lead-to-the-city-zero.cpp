class Solution {
public:
         int ans =0 ; 
    void dfs( vector<int>adj[],vector<bool>&v,int curr )
    {
        v[curr]= true ; 
        for(auto it : adj[curr])
        {
            if(!v[abs(it)])
            {
                if(it>0)
                    ans++;
                    dfs(adj,v,abs(it));
                
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int>adj[n]; 
        for(auto it : connections)
        {
           adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(-it[0]); 
        }
        
    vector<bool>v(n,false);
   // dfs(adj , v, 0);
     
   
               queue<int>q; 
                q.push(0); 
    while(!q.empty())
    {
        int curr = q.front(); 
        q.pop(); 
        v[curr]= true ;
        
        for(auto it : adj[curr])
        {
            if(!v[abs(it)])
            {
                if(it>0)
                    ans++;
                q.push(abs(it)); 
            }
        }
    }
        return ans ; 
    }
};