//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
       int l =0 , h = n-1 ; 
       while(l<h)
       {
           if(arr[l]<arr[h])
           return arr[l] ; 
           int m = (l+h)/2 ;
            if(arr[m]>=arr[h])
            l = m+1 ; 
            else
            h = m ; 
            
       }
       return arr[l] ; 
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends