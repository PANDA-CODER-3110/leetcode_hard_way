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
        queue<int>q ; 
   vector<int>adj[n+1]; 
      for(int i=0;i<pr.size();i++) adj[pr[i][1]].push_back(pr[i][0]);
        
        vector<int>d(n+1,0); 
        // for(int i=0 ; i<n;i++)
        // {
        //     if(!vis[i])
        //     {
        //         if(solve(adj,vis,i,pathvis)==true )
        //             return false ; 
        //     }
        // }
        // return true   ; 
     for(int i=0;i<pr.size();i++)
        {
            d[pr[i][0]]++;// calculating indegree
        }
        for(int i=0;i<n ;i++)
        {
            if(d[i]==0) q.push(i); //if indegree==0, push in queue
        }
        int cnt =0 ; 
        while(!q.empty())
        {
            int curr = q.front(); 
            q.pop(); 
            for(auto it : adj[curr])
            {
                d[it]--; 
                if(d[it]==0)
                    q.push(it); 
            }
            cnt++; 
            
        }
        if(cnt == n) return true ; 
        else
            return false ; 
        
    }
};