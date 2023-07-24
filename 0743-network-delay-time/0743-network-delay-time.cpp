class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>>adj[n+1] ; 
        for(auto it : times)
        {
            adj[it[0]].push_back({it[1] , it[2]}) ; 
        }
        queue<pair<int ,int>>q  ;
        q.push({k ,0}); 
         vector<int>dist(n+1, 1e9) ; 
        dist[k]  =0 ; 
        while(!q.empty())
        {
            auto it = q.front() ; 
            int node = it .first  ; 
            int cost = it.second ; 
            q.pop() ; 
            for(auto it : adj[node])
            {
                int adjnode = it.first ; 
                int dis = it.second ; 
                if(cost+dis<dist[adjnode]){
                    dist[adjnode] = cost+dis ; 
                    q.push({adjnode , dist[adjnode]}) ; 
                }
            }
                
        }
        sort(dist.begin(), dist.end());
        if(dist[n-1] == 1e9) return -1;
        return dist[n-1];
    }
};