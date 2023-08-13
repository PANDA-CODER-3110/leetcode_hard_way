class Solution {
public:
    bool isPossible(int row, int col, int n, vector<vector<int>>& grid, int distance, vector<vector<int>> &dist)
    {
        // checking that is it possible to go to new x-cordinate(row) &  y-cordinate(col) and new distance is less than previous distance 
        if(row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0 && distance + 1 < dist[row][col]) 
            return true;
        
        return false;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        // if starting point is 1 then it means that it is not possible to movie forwart in any direction
        if(grid[0][0] == 1)  
            return -1;
        
        // given that grid is N x N
        int n = grid.size();
        
        // set is used to eliminate unnecessary iterations {distance {x-cordinate, y-cordinate}}
        set<pair<int, pair<int, int>>> s;
        
        // 2-D vector for storing distance of each cordinate initally having infinite distance
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); 
        
        dist[0][0] = 1;
        s.insert({1, {0, 0}});
        
        // for generating 8 directions at each coordinate (left, right, up, down, diagonally)
        int delRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        while(!s.empty())
        {
            auto it = *(s.begin());
            int distance = it.first;
            int r = it.second.first;
            int c = it.second.second;
            s.erase(it);
            
            for(int i=0; i<8; i++)
            {
                // moving in each direction (left, right, up, down, diagonally)
                int row = r + delRow[i];
                int col = c + delCol[i];
                
                // checking if it is clear path or not and new distance is less than previous distance
                if(isPossible(row, col, n, grid, distance, dist)) 
                {
                    
                    // if set contains distance for row, col remove it from set
                    if(dist[row][col] != INT_MAX) 
                        s.erase({distance, {row, col}});
                    
                    dist[row][col] = distance + 1;
                    
                    // insert new shortest distance
                    s.insert({distance + 1, {row, col}}); 
                }
            }
        }
        
        // if last [n-1][n-1] position is still infinity it means there is no  clear path so we return -1
        if(dist[n-1][n-1] == INT_MAX) 
            return -1;
        
        return dist[n-1][n-1]; 
    }
};