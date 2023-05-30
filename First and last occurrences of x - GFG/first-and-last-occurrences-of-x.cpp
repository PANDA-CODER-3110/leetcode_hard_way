// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
   
 sort(arr,arr+n) ; 
 int start = lower_bound(arr,arr+n,x) - arr  ; 
 int end  = lower_bound(arr,arr+n,x+1) - arr -1 ; 
 if(start<n && arr[start]==x)
 return {start,end}; 
 else
 return {-1,-1}
;   
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends