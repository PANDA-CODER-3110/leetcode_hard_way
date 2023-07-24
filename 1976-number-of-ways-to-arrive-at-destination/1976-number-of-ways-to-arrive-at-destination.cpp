class Solution {
    int mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto road: roads){
            int u = road[0], v = road[1], w = road[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        vector<long long> dist(n,1e15);
        vector<int> ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            long long distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int itNode = it.first;
                long long itdistance = it.second;
                if(dist[itNode]> itdistance+distance){
                    dist[itNode] = itdistance + distance;
                    pq.push({dist[itNode],itNode});
                    ways[itNode] = ways[node];
                }
                else if(dist[itNode]==itdistance + distance){
                    ways[itNode] = (ways[itNode] + ways[node])%mod;
                    cout<<ways[itNode]<<endl;
                }
            }
        }
        return ways[n-1]%mod;
    }
};