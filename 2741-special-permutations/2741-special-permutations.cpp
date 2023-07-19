class Solution {
public:
    int dp[16385][16];
    long long mod = 1e9+7;
    long long f(vector<int>&nums,int &used,int ind,int prev,int n){

        if(ind==n){
            return 1;
        }

        if(dp[used][prev+1]!=-1) return dp[used][prev+1];

        long long cnt = 0;

        for(int i = 0;i<n;i++){
            if((used & 1<<i)==0 and (prev==-1 or nums[prev]%nums[i]==0 or nums[i]%nums[prev]==0)){
                used = used | (1<<i);
                cnt+=(f(nums,used,ind+1,i,n)%mod);
                cnt = cnt%mod;
                used = used & (~(1<<i));
            }
        }

        return dp[used][prev+1] = cnt%mod;
    }

    int specialPerm(vector<int>& nums) {
        int used = 0;
        memset(dp,-1,sizeof(dp));
        return f(nums,used,0,-1,nums.size())%mod;
    }
};