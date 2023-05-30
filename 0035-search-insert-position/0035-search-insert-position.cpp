class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int start = 0 , end = arr.size()-1 ; 
        while(start<=end)
        {
            int mid = start+(end-start)/2 ; 
            if(arr[mid]==target) return mid ; 
            if(arr[mid]<target) start = mid +1 ; 
            else 
                end = mid -1 ; 
        }
        
        return end +1 ; 
        
    }
};