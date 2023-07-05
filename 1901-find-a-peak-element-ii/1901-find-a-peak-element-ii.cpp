class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size() ; 
        int col = mat[0].size() ;
         int i =0 , j = col -1 ; 
        while(i>=0 && i<row && j>=0 && j<col)
        {
            int up = i-1<0? -1 : mat[i-1][j]  ; 
             int down = i+1>=row? -1 : mat[i+1][j]  ; 
             int left = j-1<0? -1 : mat[i][j-1]  ; 
             int right = j+1>=col? -1 : mat[i][j+1]  ; 
            if(mat[i][j]>up && mat[i][j]>down && mat[i][j]>left && mat[i][j]>right )
                return {i,j} ; 
            
            int maxx = max({up, down , left , right}) ; 
            if(maxx==up)i-- ; 
            else if(maxx==down)i++ ; 
            else if(maxx==left) j-- ; 
            else j++ ; 
        }
        return {-1,-1}; 
    }
};