class Solution {
public:
 int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        int iniRow = entrance[0];
        int iniCol = entrance[1];
        vis[iniRow][iniCol] = 1;

        queue<pair<int,pair<int,int>>> q;
        q.push({0,{iniRow,iniCol}});
        int res = -1;

        while(!q.empty()){
            int currDist = q.front().first;
            int currRow = q.front().second.first;
            int currCol = q.front().second.second;
            q.pop();
            if((currCol == 0 || currCol == (n-1) || currRow == 0 || currRow == (m-1)) && currDist != 0){
                res = currDist;
                break;
            }
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,-1,0,1};
            for(int i = 0 ; i < 4; i++){
                int nRow = currRow + delrow[i];
                int nCol = currCol + delcol[i];
                if(nRow >=0 && nRow < m && nCol >=0 && nCol < n && !vis[nRow][nCol] && maze[nRow][nCol] == '.') {
                    vis[nRow][nCol] = 1;
                    q.push({currDist + 1, {nRow,nCol}});
                }
            }
        }
        return res;
    }
};