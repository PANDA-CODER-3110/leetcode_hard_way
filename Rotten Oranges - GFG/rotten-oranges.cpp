//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
   int dir[5] = {-1 , 0 , 1, 0 ,-1}  ; 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        int m = grid[0].size() ; 
        queue<pair<pair<int ,int>, int>>q ; 
         vector<vector<int>>vis(n+1 , vector<int>(m+1 ,0))  ;
        int fresh = 0 ; 
        for(int i =0 ; i<n ; i++)
        {
            for(int j =0 ; j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0}) ;
                    vis[i][j] =1 ; 
                }
                if(grid[i][j]==1)
                fresh++ ; 
            }
        }
       
        int tim =0 ; 
        
        while(!q.empty())
        {
            int row = q.front().first.first ; 
            int col = q.front().first.second ; 
            int tm = q.front().second ;
            q.pop() ; 
            
            tim = max(tim , tm) ; 
            for(int i =0 ; i<4;i++)
            {
                int nrow = row + dir[i] ; 
                int ncol = col + dir[i+1] ; 
                if(nrow>=0 && nrow<n && ncol >=0 && ncol<m && grid[nrow][ncol]==1 
                && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] =1 ; 
                    q.push({{nrow , ncol}, tm+1}) ; 
                    fresh -- ; 
                }
            }
        }
    return (fresh==0)? tim : -1 ; 
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends