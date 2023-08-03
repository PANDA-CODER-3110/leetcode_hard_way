class Solution {
public:
    int findMin(vector<int>& arr) {
      int start =0 , end = arr.size() -1 ; 
        int ans = INT_MAX  ; 
        while(start <= end){
            int mid = (start+end)/2 ; 
            if(arr[start]<=arr[mid]){
                ans = min(ans , arr[start]) ;
                start = mid+1 ; 
            }
            else
            {
                ans = min(ans , arr[mid]) ; 
                end = mid-1 ; 
            }
            
        }
        return ans ; 
    }
};