class Solution {
public:
    int dir[5] ={-1 ,0 , 1, 0 , -1} ; 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size() ; 
        queue<pair<pair<int,int>,int>>q ; 
        int f  =0 ; 
        vector<vector<int>>vis(n+1 , vector<int>(m+1 , 0)) ; 
        for(int i=0 ; i<n;i++)
        {
            for(int j =0 ; j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0}) ; 
                    vis[i][j] = 2 ; 
                }
                if(grid[i][j]==1)
                {
                    f++ ; 
                }
                    
            }
        }
        int tm =0 ; 
        
        while(!q.empty())
        { 
            int row = q.front().first.first ; 
            int col = q.front().first.second ; 
            int time = q.front().second ; 
            q.pop() ; 
            tm = max(tm  , time) ; 
            for(int i=0 ;i<4;i++)
            {
                int nrow = row+dir[i] ; 
                int ncol = col+dir[i+1] ; 
                if(nrow>=0  && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({{nrow, ncol },time+1}) ; 
                    vis[nrow][ncol] = 2 ; 
                    f-- ; 
                }
            }
         }
        
     if(f==0) return tm ; 
        return -1 ; 
    }
};