class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int cnt =0 ;  
	    for(int i=0 ; i<arr.size();i++)
	    {
	        if(arr[i]!=0)
	        {
	            swap(arr[cnt] , arr[i]) ; 
	            cnt++   ; 
	        }
	    }
    }
};