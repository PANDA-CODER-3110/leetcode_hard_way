//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int f(int ind, int arr[], int n, vector<int> &dp){
	     if(ind>=n)
	     return 0 ; 
	     if(dp[ind]!=-1)
	     return dp[ind] ; 
	     int nottake = f(ind+1,arr,n,dp); 
	     int take = arr[ind]+f(ind+2,arr,n,dp) ; 
	     
	     return dp[ind] = max(take , nottake) ; 
	 }
    int FindMaxSum(int arr[], int n)
    {
        vector<int>dp(n+2, 0);
    //  return f(0, arr, n, dp);
   
      for(int i=n-1 ; i>=0;i--){
          int take = arr[i]+ dp[i+2] ; 
          int nottake = dp[i+1] ; 
          dp[i] = max(take , nottake) ; 
      }
      return dp[0] ;  
     
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends