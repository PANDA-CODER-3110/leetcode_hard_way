//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
   static bool comp(pair<double,int>&a,pair<double ,int>&b)
    {
        return a.first>b.first;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>>m;
        
        for(int i=0;i<n;i++)
        {
          //  m[(arr[i].value)/(arr[i].weight)]=i;
            m.push_back(make_pair((1.0*arr[i].value)/(arr[i].weight),i));
            
        }
        sort(m.begin(),m.end(),comp);
        double v=0;
        double w=0;
        for(auto x:m)
        {
            if(W>=w+arr[x.second].weight)
            {
                w+=arr[x.second].weight;
                v+=arr[x.second].value;
                
            }
            else if(W < w+arr[x.second].weight)
            {
                double wei=W-w;
                //cout<<v<<endl;
                v+=(wei/arr[x.second].weight)*arr[x.second].value;
        
                w+=wei;
            }
            
        }
        
       
       return v;  // Your code here
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends