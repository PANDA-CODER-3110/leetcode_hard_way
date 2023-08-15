class Solution {
public:
    int dir[5] = {-1 , 0 , 1 , 0, -1 }  ;
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        int m = grid[0].size() ; 
        vector<vector<int>>time(n , vector<int>(m , INT_MAX)) ; 
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int , int>>>,greater<pair<int , pair<int,int>>>>pq ; 
        time[0][0] = grid[0][0] ; 
        pq.push({time[0][0],{0 , 0}});     
        while(!pq.empty())
        {
            int tim = pq.top().first ; 
            int row = pq.top().second.first ; 
            int col = pq.top().second.second ; 
            pq.pop() ;
           
            for(int i =0  ; i<4 ; i++)
            {
                int nrow = row+dir[i] ; 
                int ncol = col + dir[i+1] ; 
                if(nrow>=0 && ncol>=0 && nrow<n && ncol <m)
                {
                     int maxi = max(tim , grid[nrow][ncol] ) ; 
                    if(time[nrow][ncol]>maxi)
                    {
                        time[nrow][ncol] = maxi ; 
                        pq.push({time[nrow][ncol] ,{nrow , ncol}} ) ; 
                    }
                }
            }
            
        }
        
        return time[n-1][m-1] ; 
    }
};