class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1 ; 
        for(;i>0;i--)
        {
            if(nums[i-1]<nums[i])
                break ; 
        }
        
        if(i==0)
            reverse(nums.begin(),nums.end());
        else
        { int val=nums[i-1];
        int j=nums.size()-1;
        while(j>=i){
            if(nums[j]>val)
                break;
            j--;
        }
        swap(nums[j],nums[i-1]);
         reverse(nums.begin()+i,nums.end()); }
           // next_permutation(nums.begin(),nums.end());
        
    }
};