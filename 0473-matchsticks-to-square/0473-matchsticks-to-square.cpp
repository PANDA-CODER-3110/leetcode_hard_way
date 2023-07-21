class Solution {
public:
     bool solve(int z,int &n,int x,int &s,int y,vector<int> &v,vector<int> &dp){
        if(y==4){
            return true;
        }
        if(z == (1<<n)-1){
            return true;
        }
        if(dp[z] != -1)return dp[z];
        bool a = false;
        for(int i = 0; i < n; i++){
            if((z&(1<<i))==0){
                x += v[i];
                if(x<s){
                    a |= solve(z|(1<<i),n,x,s,y,v,dp);
                }else if(s==x){
                    a |= solve(z|(1<<i),n,0,s,y+1,v,dp);
                }
                x -= v[i];
            }
        }
        return dp[z] = a;
    }
    bool makesquare(vector<int>& v) {
        int s = 0;
        for(auto &i: v){
            s += i;
        }
        if(s%4)return false;
        s /= 4;
        int n = v.size();
        sort(v.begin(),v.end());
        vector<int> dp((1<<n)+15,-1);
        return solve(0,n,0,s,0,v,dp);
    }
};