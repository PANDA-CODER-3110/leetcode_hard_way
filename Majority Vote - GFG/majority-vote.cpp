//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
       vector<int>ans ; 
       int num1 = nums[0] , cnt=1 , cnt1 =1 , num2 = nums[1] ; 
       for(int i=2 ; i<nums.size();i++)
       {
           if(nums[i]==num1)
           cnt++ ; 
           else if(nums[i]==num2)
           cnt1 ++ ; 
           else if(cnt==0)
           {
               num1=nums[i] ; 
               cnt++ ;
           }
           else if(cnt1==0)
           {
               num2 = nums[i] ; 
               cnt1++ ; 
           }
           else
           {
               cnt1-- ; 
               cnt-- ; 
           }
       }
       cnt =0 , cnt1 =0 ; ;
       for(int i =0 ; i<n;i++)
       {
           if(nums[i]==num1)
           cnt++ ; 
           else if(nums[i]==num2)
           cnt1++ ; 
       }
       if(cnt>n/3)ans.push_back(num1) ; 
       if(cnt1>n/3)ans.push_back(num2) ;
       if(ans.size()) return ans ; 
       else {
       ans.push_back(-1) ; 
       return ans ; 
       }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends