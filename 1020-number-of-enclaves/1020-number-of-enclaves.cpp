class Solution {
public:
    /// similar to  surrounded region//----------------------------------------------------
     vector<int>dir={-1,0,1,0,-1};
    int numEnclaves(vector<vector<int>>&b) {
         int n = b.size();
        int m = b[0].size(); 
        queue<pair<int,int>>q; 
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0 ; j<m;j++)
        {
            if(b[0][j]== 1)
            {
               q.push({0,j});
                b[0][j] = 2;
            }
            if(b[n-1][j]==1)
            {
        
                q.push({n-1,j});
                b[n-1][j] = 2;
            }
        }
         for(int i=0 ; i<n;i++)
        {
            if(b[i][0]==1)
            {
                q.push({i,0});
                b[i][0] = 2;
            }
            if(b[i][m-1]==1)
            {
               
                q.push({i,m-1});
                b[i][m-1] =2;
            }
        }
      while(!q.empty())
      {
          int row = q.front().first; 
          int col = q.front().second; 
          q.pop(); 
          for(int i=0 ; i<4;i++)
          {
                int nrow = row+dir[i]; 
                    int ncol = col+dir[i+1]; 
                    if( nrow>=0 && ncol>=0 && nrow<b.size() && ncol<b[0].size() && b[nrow][ncol]==1)
                    {
                        q.push({nrow,ncol}); 
                        b[nrow][ncol]= 2; 
                    }
          }
      }
        int ans =0 ; 
        for(int i=0 ; i<n;i++)
        {
            for(int j=0 ; j<m;j++)
            {
                if(b[i][j]==1)
                    ans++;
            }
        }
        
        return ans ;

    }
};