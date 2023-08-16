class Solution {
public:  


int vis[500][500] ;

bool lap = true ;

void help(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& grid2, int n, int m){
   if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid2[i][j]==0){
       return ; 
   } 

   if((grid2[i][j] == 1 && grid[i][j]==0) ){
       lap = false ; 
       return ;
   }

   vis[i][j] =1 ; 

   help(i+1,j,grid,grid2,n,m);
   help(i,j+1,grid,grid2,n,m) ;
   help(i-1,j,grid,grid2,n,m) ;
   help(i,j-1,grid,grid2,n,m);

   return ;

}



    int countSubIslands(vector<vector<int>>& grid, vector<vector<int>>& grid2) {
       int n = grid.size();
       int m  = grid[0].size(); 
       int ans =0 ;

       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               vis[i][j]=0;
           }
       }

       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(grid2[i][j]==1 && grid[i][j]==1 && vis[i][j]==0){
                   help(i,j,grid,grid2,n,m);
                   if(lap){
                       ans++;
                   }
                   lap = true ; 
               }
               
           }
       }

       return ans ;

    }
};