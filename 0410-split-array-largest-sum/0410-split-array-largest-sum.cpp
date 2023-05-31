class Solution {
public:
    bool can(vector<int>& nums, int k,int m )
    {
        int cnt =1 , sum =0 ; 
        for(int i=0 ;i<nums.size();i++)
        {
            sum +=nums[i] ; 
            if(sum > m)
            {
                sum = nums[i] ; 
                cnt++ ; 
            }
            
        }
        return (cnt<=k) ; 
    }
    int splitArray(vector<int>& nums, int k) {
        int l =0  , r =0  ; 
        for(int i=0 ; i<nums.size();i++)
        {
            r+=nums[i] ; 
            l = max(l , nums[i]) ; 
        }
        while(l<=r)
        {
            int m = (l+r)/2 ; 
            if(can(nums, k , m))
            {
                r = m-1 ; 
            }
            else
                l = m+1 ; 
        }
        
        return l ; 
    }
   
   
};