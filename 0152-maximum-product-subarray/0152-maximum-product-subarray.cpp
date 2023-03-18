class Solution {
public:
    int maxProduct(vector<int>& nums) {
      //  ------------------------------------------- O(2N)---------------------------------------------------//
    // int prod =1 ; 
    //     bool zero = false ; 
    //     int lef = INT_MIN,rig= INT_MIN; 
    //     for(int i=0 ; i<nums.size();i++)
    //     {
    //         if(nums[i]==0)
    //         { prod =1 ;
    //          zero = true ; 
    //          continue ; }
    //         prod *= nums[i]; 
    //         lef = max(lef,max(prod,nums[i]));
    //     }
    //     prod =1 ; 
    //     for(int j= nums.size()-1 ; j>=0 ; j--)
    //     {
    //         if(nums[j]==0)
    //         {
    //             prod =1 ;
    //             zero = true ; 
    //             continue ; 
    //         }
    //         prod*=nums[j]; 
    //         rig = max(rig,max(prod,nums[j])); 
    //     }
    //     if(zero == true )
    //     return max(lef,max(rig,0)); 
    //     else
    //         return max(lef,rig); 
        
        int ma = nums[0]; 
        int mi = nums[0]; 
        int ans = nums[0]; 
        for(int i=1 ;i<nums.size();i++)
        {
            if(nums[i]<0)
                swap(ma,mi); 
         ma=max(nums[i],nums[i]*ma);
            mi=min(nums[i],nums[i]*mi);
            ans = max(ans , ma ); 
        }
        
        return ans ; 
    }
};