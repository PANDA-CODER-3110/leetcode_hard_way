class Solution {
public:
    int removeDuplicates(vector<int>&A) {
        int i =0  , ans =0 , id =0 ; 
        while(i<A.size())
        {
            int temp = A[i] ; 
            ans ++ ; 
            A[id] = temp  ;
            while(i<A.size()&& A[i]==temp)
                i++ ; 
            id++ ; 
        }
        return ans ; 
    }
};