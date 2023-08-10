class Solution {
public:
    int findMin(vector<int>& arr) {
     int lo = -1 , hi = arr.size() -1 ; 
        while(lo+1<hi)
        {
            int mid = lo+floor((hi - lo)/2) ; 
            if(arr[mid]<=arr[hi ])
            {
                hi = mid ; 
            }
            else
                lo = mid ; 
                
        }
        return arr[hi] ; 
    }
};