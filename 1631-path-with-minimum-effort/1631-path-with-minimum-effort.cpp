class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int,int>> , vector<pair<int , pair<int,int>>> , greater<pair<int ,pair<int , int>>>>pq ; 
        int n = heights.size() ; 
        int m = heights[0].size() ; 
        vector<vector<int>>dist(n , vector<int>(m, 1e9)) ; 
        dist[0][0] =0 ; 
        pq.push({0,{0,0}}) ; 
        int dirx[]= {-1 , 0 , 1 ,0} ; 
        int diry[] = {0 , 1 ,0, -1} ; 
        while(!pq.empty())
        {
            int diff = pq.top().first ; 
            int row = pq.top().second.first ; 
            int col = pq.top().second.second ; 
            pq.pop() ; 
            if(row==n-1 && col == m-1) return diff ; 
            for(int i=0 ; i<4;i++){
                int nrow = row+dirx[i] ; 
                int ncol = col + diry[i] ;
                if(nrow>=0 && nrow<n && ncol >=0 && ncol <m){
                    int new_eff = max(abs(heights[row][col] - heights[nrow][ncol]) , diff) ; 
                if(new_eff<dist[nrow][ncol])
                {
                    dist[nrow][ncol] = new_eff ; 
                    pq.push({new_eff , {nrow,ncol}}) ; 
                }
                }
                
            }
            cout<<diff ; 
        }
         return 0 ; 
    }
};