class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int prod =1 ; 
        bool zero = false ; 
        int lef = INT_MIN,rig= INT_MIN; 
        for(int i=0 ; i<nums.size();i++)
        {
            if(nums[i]==0)
            { prod =1 ;
             zero = true ; 
             continue ; }
            prod *= nums[i]; 
            lef = max(lef,max(prod,nums[i]));
        }
        prod =1 ; 
        for(int j= nums.size()-1 ; j>=0 ; j--)
        {
            if(nums[j]==0)
            {
                prod =1 ;
                zero = true ; 
                continue ; 
            }
            prod*=nums[j]; 
            rig = max(rig,max(prod,nums[j])); 
        }
        if(zero == true )
        return max(lef,max(rig,0)); 
        else
            return max(lef,rig); 
    }
};