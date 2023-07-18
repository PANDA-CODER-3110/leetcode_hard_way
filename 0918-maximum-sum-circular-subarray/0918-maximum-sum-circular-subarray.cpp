class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=0;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int sum1=0;
        int sum2=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            if(sum1<0)sum1=0;
            sum1+=nums[i];
            maxi=max(maxi,sum1);
            if(sum2>0)sum2=0;
            sum2+=nums[i];
            mini=min(mini,sum2);
        }
        if(total-mini==0)return maxi;
        return max(maxi,total-mini);
    }
};