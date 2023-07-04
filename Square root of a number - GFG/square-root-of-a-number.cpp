//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long int start =0 , end = x ; 
        while(start<=end)
        {
            long long int m = (start+end)/2 ; 
            if(m*m==x) return m  ;
            else if(m*m<x)
            start = m+1 ; 
            else
            end = m-1; 
        }
        
        return end  ;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends