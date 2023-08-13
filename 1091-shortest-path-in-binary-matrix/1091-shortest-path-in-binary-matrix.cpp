typedef pair<int,pair<int,int>> pi;
class Solution {
public:
    int dx[8]={0,1,-1,0,1,-1,-1,1};
    int dy[8]={1,0,0,-1,1,-1,1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int res = 1;
// int row = grid.size();
// if (row == 0) return -1;
// int col = grid[0].size();
// if (col == 0 ) return -1;
// if (grid[0][0] != 0 | grid[row-1][col-1] != 0) return -1;

//     queue<pair<int, int>> queue;
//     queue.push(make_pair(0,0));
//     vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
//     grid[0][0] = 1;
//     while(!queue.empty()){
//         auto curr = queue.front();
//         int x = curr.first, y = curr.second;
//         if( x == row -1 && y == col -1) return grid[x][y];
        
//         for(auto direction : directions){
//             int nx = x + direction[0];
//             int ny = y + direction[1];
//             if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 0){
//                 queue.push(make_pair(nx,ny));
//                 grid[nx][ny] = grid[x][y] + 1;
//             }
//         }
//         queue.pop();
//     }
//     return -1;
         int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        if(grid[0][0]==1 or grid[n-1][n-1]==1)
            return -1;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({1,{0,0}});
        dist[0][0]=1;
        while(!pq.empty())
        {
            int cnt=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(int k=0;k<=7;k++)
            {
                int newx=x+dx[k];
                int newy=y+dy[k];
                if(newx<0 or newy<0 or newx>=n or newy>=n or grid[newx][newy]==1)
                    continue;
                if(dist[newx][newy]>1+cnt)
                {
                    dist[newx][newy]=1+cnt;
                    pq.push({dist[newx][newy],{newx,newy}});
                }
            }
        }
        if(dist[n-1][n-1]==1e9)
            return -1;
        return dist[n-1][n-1];
        
    }
};