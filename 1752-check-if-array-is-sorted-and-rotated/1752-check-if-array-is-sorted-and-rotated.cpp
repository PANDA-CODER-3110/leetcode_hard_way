class Solution {
public:
    bool check(vector<int>& arr) {
        int x =0 ; 
        for(int i=0 ; i<arr.size();i++)
        {
            if(arr[i]>arr[(i+1)%arr.size()])
            {
                  x++;
            }
            
        }
     return (x<=1) ; 
        
    }
};