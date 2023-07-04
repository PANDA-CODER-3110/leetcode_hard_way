class Solution {
public:
    int findMin(vector<int>& arr) {
         int l =0 , h = arr.size()-1 ; 
       while(l<h)
       {
           if(arr[l]<arr[h])
           return arr[l] ; 
           int m = (l+h)/2 ;
            if(arr[m]>=arr[h])
            l = m+1 ; 
            else
            h = m ; 
            
       }
       return arr[l] ; 
    }
};