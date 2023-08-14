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
        set<pair<long long , int>>st ; 
        vector<long long> dist(n,1e15);
        vector<int> ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        st.insert({0 ,0}) ; 
        while(st.size()){
            auto pl = (*st.begin()) ; 
            long long distance = pl.first;
            int node = pl.second;
            st.erase(pl) ; 
            for(auto it: adj[node]){
                int itNode = it.first;
                long long itdistance = it.second;
                if(dist[itNode]> itdistance+distance){
                    st.erase({dist[itNode] , itNode}) ; 
                    dist[itNode] = itdistance + distance;
                    st.insert({dist[itNode] , itNode}) ; 
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