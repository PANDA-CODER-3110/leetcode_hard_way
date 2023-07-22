class Solution {
public:
    void dfs(vector<int>&vis , vector<vector<int>>& M , int node)
    {
        vis[node] =1 ; 
        for(int i =0 ; i<M[node].size();i++)
        {
            if(vis[i]!=1 && M[node][i])
                dfs(vis , M , i) ; 
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ; 
     vector<int>vis(n+1 , 0) ;
         int cnt=0 ; 
        for(int i=0 ; i<n;i++)
        {
            if(!vis[i])
            {
                 cnt++ ; 
                dfs(vis , isConnected,i ) ; 
                   
            }
        }
        return cnt ; 
    }
};