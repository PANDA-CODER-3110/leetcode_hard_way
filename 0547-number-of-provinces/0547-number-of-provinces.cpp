class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ; 
       vector<int>vis(n , 0 ) ; 
           int cnt =0 ; 
       for(int i =0 ; i<n; i++)
       {
           if(vis[i])
               continue ;
           queue<int>q ; 
           cnt++ ; 
           q.push(i) ; 
           while(!q.empty())
           {
               int node = q.front() ; 
               q.pop() ; 
               vis[node] = 1 ; 
               for(int j=0 ; j<isConnected[node].size();j++ )
                {
                    if(!vis[j] && isConnected[node][j]==1)
                    {
                        q.push(j); 
                        vis[j]= true; 
                    }
                }
           }
            
        }
        
        return cnt ; 
    }
};