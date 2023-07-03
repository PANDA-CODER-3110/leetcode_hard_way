// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int>nums){
         int i = nums.size()-1 ; 
        for(;i>0;i--)
        {
            if(nums[i-1]<nums[i])
                break ; 
        }
        
        if(i==0)
            reverse(nums.begin(),nums.end());
        else
        { int val=nums[i-1];
        int j=nums.size()-1;
        while(j>=i){
            if(nums[j]>val)
                break;
            j--;
        }
        swap(nums[j],nums[i-1]);
         reverse(nums.begin()+i,nums.end()); }
         return nums ; 
         
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends