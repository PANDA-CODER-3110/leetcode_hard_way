class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size() ; 
        int col = mat[0].size() ; 
        int i= 0  , j = col -1 ; 
        while(i>=0  && i<row  && j>=0  && j<col)
        {
            int up = i-1<0 ? -1 : mat[i-1][j] ; 
            int down = i+1>=row ? -1 : mat[i+1][j] ; 
            int l = j-1<0 ? -1 : mat[i][j-1] ; 
            int r = j+1>=col ? -1 : mat[i][j+1] ;
            
            if(mat[i][j]>up && mat[i][j]>down && mat[i][j]>l && mat[i][j]>r)
                return {i,j} ; 
            
            int maxx = max({up , down ,  l , r}) ; 
            
            if(maxx==up) i-- ; 
            else if(maxx== down) i++  ;
            else if(maxx==l) j-- ; 
            else j++ ; 
        }
        
        return {-1,-1}; 
    }
};