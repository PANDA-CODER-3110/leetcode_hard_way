class Solution {
public:
    int arraySign(vector<int>& nums) {
        int x =0 ; 
        for(auto it : nums)
        {
            if(it<0)
                x++ ; 
            if(it==0)
                return 0 ; 
        }
        if(x%2) return -1 ; 
        else return 1 ; 
    }
};