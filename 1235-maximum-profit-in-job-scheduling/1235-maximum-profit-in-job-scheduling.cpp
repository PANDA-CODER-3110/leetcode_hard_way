class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
         int n=startTime.size();
        vector<vector<int>>nums(n);
        for(int i=0;i<n;i++){
            nums[i].push_back(startTime[i]);
            nums[i].push_back(endTime[i]);
            nums[i].push_back(profit[i]);
        }
        sort(startTime.begin(),startTime.end());
        sort(nums.begin(),nums.end());
        vector<int>dp(n,-1);
        return find(nums,0,n,dp,startTime);
        
    }
    int find(vector<vector<int>>&nums,int i,int &n,vector<int>&dp,vector<int>& st){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int x=lower_bound(st.begin(),st.end(),nums[i][1])-st.begin();
        int a=nums[i][2]+find(nums,x,n,dp,st);
        int b=find(nums,i+1,n,dp,st);
        return dp[i]=max(a,b);
    }
};