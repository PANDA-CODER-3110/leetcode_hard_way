class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); 
     if(n==0)  return 0 ; 
        vector<bool>vis(n,false); 
        int pro =0 ; 
        for(int i=0 ; i<n;i++)
        {
            if(!vis[i])
            {
                pro++;
                dfs(i,isConnected,vis);
            }
        }
        return pro ; 
    }
    void dfs(int i  , vector<vector<int>>&M, vector<bool>&v)
    {
        v[i] = true ; 
        for(int j=0 ; j<M[i].size();j++)
        {
            if(M[i][j] && !v[j])
            {
                dfs(j,M,v);
            }
        }
    }
};