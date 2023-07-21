class Solution {
public:

    int solve(vector<int>& nums, int i,vector<int>& dp)
    {
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1)return dp[i];
        int curr_value = nums[i];
        int curr_sum = nums[i];
        int new_index = i+1;
        // jab tak ele same hai tab tak add karo 
        while(new_index<nums.size() && nums[new_index] == curr_value)
        {
            curr_sum+=nums[i];
            new_index++;
        }
        // agar next index pehle index ka +1 hai to hum nhi lenge na 
        //isiliye new_index ko badhao aage 
        // like  2 2 2 3 3 4 me agar 2 liya to 3 nhi lenge 
        // isiliye 4 pe gye 
        while(new_index<nums.size() && nums[new_index] == curr_value +1)
        {
            new_index++;
        }
        // sum lena hai ki nhi vo apne haath me hai 
        // isiliye hum jo abhi tak ka curr sum aya 
        // aur jab nhi liya us elemnt ko unka max le rhe hai
        int take_sum = curr_sum + solve(nums,new_index,dp);
        int not_take_sum = solve(nums,i+1,dp);
        dp[i] = max(take_sum , not_take_sum);
        return dp[i];
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,-1);
        return solve(nums,0,dp);
    }
};