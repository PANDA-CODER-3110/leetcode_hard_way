class Solution {
public:
    int pivotIndex(vector<int>& nums) {
         int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        
        int l=0,r=sum;
        for(int i=0;i<nums.size();i++)
        {
            r=r-nums[i];
            if(r==l)
                return i;
            l=l+nums[i];
        }
        return -1;
    }
};