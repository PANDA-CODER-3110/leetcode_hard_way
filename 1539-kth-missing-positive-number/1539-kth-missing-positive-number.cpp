class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l =0 , r = arr.size()-1 ; 
        while(l<=r)
        {
            int m = (r+l)/2 ; 
            if(arr[m] - m - 1 >= k)
                r = m-1 ; 
            else 
                l = m+1 ; 
        }
        return l+k ; 
    }
};
  
       