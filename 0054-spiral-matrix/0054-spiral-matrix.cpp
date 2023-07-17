class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size() ; 
        int m = matrix[0].size() ; 
        vector<int>res ; 
        int left =0 , right = m-1 , top =0 , bottom = n-1 ; 
        int direction = 1; 
        while(left<=right && top<=bottom)
        {
            if(direction ==1)
            {
                for(int i = left ; i<=right ;i++)
                {
                    res.push_back(matrix[top][i]) ; 
                }
                direction =2 ; 
                top++ ; 
            }
            else if(direction ==2)
            {
                for(int i = top ; i<=bottom ;i++)
                {
                res .push_back(matrix[i][right]) ; 
                }
                direction = 3 ; 
                right -- ; 
            }
            else if(direction == 3)
            {
                 for(int i = right ; i>=left ;i--)
                {
                res .push_back(matrix[bottom][i]) ; 
                }
                direction = 4 ; 
                bottom --  ; 
            }
            else
            {
                 for(int i = bottom ; i>=top ;i--)
                {
                res .push_back(matrix[i][left]) ; 
                }
                direction = 1 ; 
                left ++  ; 
            }
                
        }
         return res ; 
    }
};