class Solution {
public:
    int findMin(vector<int>& arr) {
       auto ans = *min_element(arr.begin() , arr.end()) ;
       return ans ; 
    }
};