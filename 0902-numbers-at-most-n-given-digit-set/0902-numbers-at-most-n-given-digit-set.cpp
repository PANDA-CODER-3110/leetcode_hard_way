class Solution {
public:
    int dp[10][2][90];
    int mod = 1e9+7;
    int solve(int ind,int is_prevented,string &s,vector<int>&nums,int sum){
        if(ind == s.length()){
            return 1;
        }
        if(dp[ind][is_prevented][sum]!=-1){
            return dp[ind][is_prevented][sum];
        }
        int ans = 0;
        if(is_prevented){
            for(int i=0;i<nums.size();i++){
                if((i==0 && sum>0) || nums[i]>(s[ind]-'0')){
                    continue;
                }
                else{
                    if(nums[i]==s[ind]-'0'){
                        ans = (ans + solve(ind+1,true,s,nums,sum+nums[i])%mod)%mod;
                    }
                    else{
                        ans = (ans + solve(ind+1,false,s,nums,sum+nums[i])%mod)%mod;
                    }
                }
            }
        }
        else{
            for(int i=0;i<nums.size();i++){ 
                if(i==0 && sum>0){
                    continue;
                }
                ans = (ans + solve(ind+1,false,s,nums,sum+nums[i])%mod)%mod;
            }
        }
        return dp[ind][is_prevented][sum] = ans%mod;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        vector<int> nums;
        nums.push_back(0);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<digits.size();i++){
            nums.push_back(digits[i][0]-'0');
        }
        return solve(0,true,s,nums,0)-1;
    }
};