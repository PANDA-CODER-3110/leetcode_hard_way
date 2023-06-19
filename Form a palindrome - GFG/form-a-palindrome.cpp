//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  
  int solve(string x, string y , int m , int n, vector<vector<int>>&dp )
  {
      if(n==0 || m==0)
      return  0  ; 
      
      if(dp[n][m]!=-1)
      return dp[n][m] ;
      
      if(x[m-1]==y[n-1])
      return dp[n][m] =  1 + solve(x,y,m-1 , n-1,dp );
       
       else
        return dp[n][m] = max(solve(x,y,m-1 , n,dp), solve(x,y,m,n-1,dp)) ; 
  }
    int countMin(string str){
     string str2 = str ;
     reverse(str2.begin(), str2.end()) ; 
     vector<vector<int>>dp(str.size()+1,vector<int>(str.size()+1,-1)) ; 
     int ans = solve(str , str2 , str.length(), str2.length(),dp) ; 
     return str.size() - ans ; 
     
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends