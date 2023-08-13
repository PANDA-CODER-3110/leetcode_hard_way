class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n] ; 
        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1] , it[2]}) ; 
        }
        
        priority_queue<pair<int, pair<int , int >>, vector<pair<int, pair<int , int >>> , greater<pair<int, pair<int , int >>>>q ;
        q.push({0 ,{src,0}}) ; 
        vector<int>dist(n , 1e9) ; 
        dist[src  ]  =0 ; 
        while(!q.empty())
        {
            auto it = q.top() ; 
            q.pop() ; 
            int stops = it.first ; 
            int node = it.second.first ; 
            int cost = it.second.second  ; 
            if(stops>k)
                continue ; 
            for(auto pt : adj[node])
            {
                int adjnode = pt.first ; 
                int dis = pt.second ; 
                if(cost +dis<dist[adjnode] && stops<=k)
                {
                    dist[adjnode] = cost+ dis ; 
                    q.push({stops+1 , {adjnode , dist[adjnode]}})  ;
                    
                }
            }
        }
    return dist[dst]==1e9? -1 : dist[dst] ; 
        
    }
};