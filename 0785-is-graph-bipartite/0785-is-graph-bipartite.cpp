class Solution {
public:
 
    // bool dfs(int v, int c, vector<vector<int>>& graph){
    //     vis[v]=1;
    //     col[v]=c;
    //     for(int child:graph[v]){
    //         if(vis[child]==0){
    //             if(dfs(child,c^1,graph)==false) 
    //                 return false;
    //         }
    //         else{
    //             if(col[v]==col[child])
    //                 return false;
    //         }
    //     }
    //     return true;
    // }
    bool bip(vector<vector<int>>&graph,int idx ,  vector<int>&col )
    {
        if(col[idx]==-1) col[idx] = 1;
        for(auto &it : graph[idx])
        {
            if(col[it]==-1)
            {
                col[it]=1-col[idx] ;
                if(bip(graph,it,col)==false ) 
                    return false ; 
            } 
            else if(col[it]==col[idx])
                return false ; 
        }
        return true ; 
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
           vector<int>col(n,-1);
        for(int i=0;i<n;++i)
        {
           if(col[i]==-1)
            {
                if(bip(graph,i,col)==false){ // check for all the components of graph
                    return false;
                }
            }   
        } 
        
        
        return true;
    }
};