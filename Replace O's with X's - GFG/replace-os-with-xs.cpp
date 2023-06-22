//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int>dir={-1,0,1,0,-1};
    vector<vector<char>> fill(int n, int m, vector<vector<char>>b)
    {
          queue<pair<int,int>>q; 
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0 ; j<m;j++)
        {
            if(b[0][j]=='O' && !vis[0][j])
            {
               q.push({0,j});
                b[0][j] = 'B';
            }
            if(b[n-1][j]=='O' && vis[n-1][j]==0)
            {
        
                q.push({n-1,j});
                b[n-1][j] = 'B';
            }
        }
         for(int i=0 ; i<n;i++)
        {
            if(b[i][0]=='O' && !vis[i][0])
            {
                q.push({i,0});
                b[i][0] = 'B';
            }
            if(b[i][m-1]=='O' && !vis[i][m-1])
            {
               
                q.push({i,m-1});
                b[i][m-1] = 'B';
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
                    if( nrow>=0 && ncol>=0 && nrow<b.size() && ncol<b[0].size() && b[nrow][ncol]=='O')
                    {
                        q.push({nrow,ncol}); 
                        b[nrow][ncol]= 'B'; 
                    }
          }
      }
        for(int i=0 ; i<n;i++)
        {
            for(int j=0 ; j<m;j++)
            {
                if(b[i][j]=='O')
                    b[i][j]='X';
                else if(b[i][j]=='B')
                    b[i][j]= 'O'; 
            }
        }
        
        return b ; 

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends