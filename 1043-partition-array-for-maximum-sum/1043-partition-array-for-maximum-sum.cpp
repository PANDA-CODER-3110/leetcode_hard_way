class Solution {
public:
    int solve(int ind ,vector<int>& arr, int k  , vector<int>&dp ){
        if(ind==arr.size())
            return 0 ; 
        if(dp[ind]!=-1)
            return dp[ind] ; 
        int len =0 ;
        int maxi =INT_MIN ; 
        int maxans = INT_MIN ; 
        int n = arr.size() ; 
        int lim = min(n,ind+k) ; 
        for(int j =ind ; j< lim ; j++)
        {
            len++ ; 
            maxi = max(maxi , arr[j]) ; 
            int sum = (len*maxi) + solve(j+1 , arr, k , dp) ; 
            maxans= max(maxans , sum) ; 
        }
        
        return dp[ind] = maxans   ;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
          int n = arr.size() ; 
        vector<int>dp(arr.size()+1 , 0)  ; 
       // return solve(0 , arr , k ,dp) ; 
        for(int i = n-1 ;i>=0 ; i-- ){
             int len =0 ;
            int maxi =INT_MIN ; 
            int maxans = INT_MIN ; 
            int n = arr.size() ; 
            int lim = min(n,i+k) ; 
            for(int j =i ; j< lim ; j++)
            {
                len++ ; 
                maxi = max(maxi , arr[j]) ; 
                int sum = (len*maxi) + dp[j+1] ; 
                maxans= max(maxans , sum) ; 
            }

        dp[i] = maxans   ;
        }
        
        return dp[0] ; 
    }
};