//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int knapsack(int W, int wt[], int val[], int n,vector<vector<int>>&t)
    {
       if(n==0)
       {
           if(wt[0]<=W)
           return val[0] ; 
           return 0 ; 
       }
       
        if(t[n][W]!=-1)
        return t[n][W];
        
        if(wt[n]<=W)
        {
            return t[n][W]= max(val[n]+knapsack(W-wt[n],wt,val,n-1,t),knapsack(W,wt,val,n-1,t));
        }
        else
        {
            return t[n][W]= knapsack(W,wt,val,n-1,t);
        }
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>t(n,vector<int>(W+1,-1));
       
       return knapsack(W,wt,val,n-1,t);
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends