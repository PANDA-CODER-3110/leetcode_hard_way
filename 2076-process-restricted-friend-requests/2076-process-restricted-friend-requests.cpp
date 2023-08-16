class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:

    bool is_valid(DisjointSet ds,int n,int u,int v,map<pair<int,int>,bool> &not_join){
        ds.unionByRank(u,v);

        for(auto it:not_join){
            int u1=it.first.first;
            int v1=it.first.second;
            if(ds.findUPar(u1)==ds.findUPar(v1)){
                return false;
            }
        }
        return true;
    }

    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        
        DisjointSet ds(n);
        vector<bool> ans;
        map<pair<int,int>,bool> not_join;

        for(auto it:restrictions){
            not_join[{it[0],it[1]}]=true;
            not_join[{it[1],it[0]}]=true;
        }

        for(auto it:requests){

            int u=it[0];
            int v=it[1];

            if(ds.findUPar(u)==ds.findUPar(v)){
                ans.push_back(true);
                continue;
            }
            else{

                if(is_valid(ds,n,u,v,not_join)){
                    ds.unionByRank(u,v);
                    ans.push_back(true);
                }
                else{
                    ans.push_back(false);
                }

            }

        }

        return ans;

    }
};