// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(vector<int> a, int b, 
    int sum , vector<int>arr, vector<vector<int>> &ans , int index )
    {
        if(sum == b)
        {
            ans.push_back(arr);
            return ;
        }
        
    for(int i=index;i<a.size();i++)
    {
        if(sum+a[i]<=b)
        {
            sum+=a[i];
            arr.push_back(a[i]);
            solve(a,b,sum,arr,ans,i);
            sum-=a[i];
            arr.pop_back();
            
        }
    }
    
    return ;
    }
    
    vector<vector<int> > combinationSum(vector<int> &a, int b) {
       sort(a.begin(),a.end());
       a.erase(std::unique(a.begin(),a.end()),a.end());
       vector<vector<int>>ans;
       vector<int>arr;
       int sum=0;
       solve(a,b,sum,arr,ans,0);
       return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends