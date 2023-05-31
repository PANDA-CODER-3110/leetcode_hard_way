//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool good(int x, vector<int> &bd, int m, int k) {
        int cnt = 0, n = 0;
        for(int i=0; i<bd.size(); i++) {
            bd[i] <= x ? n++ : n = 0;
            if(n == k) cnt++, n = 0;
        }
        return cnt < m ? false : true;
    }
    int solve(int m, int k, vector<int> &bloomDay){
        int start = 0 , end = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = INT_MAX;
        if(m*k >bloomDay.size()) return -1;
   // cout<<end;
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(good(mid,bloomDay,m,k))
                {
                    end = mid -1 ;
                }
                else
                {
                    start = mid+1 ;
                   
                }
        }
            if(good(start,bloomDay,m , k))
            return start ; 
            else
            return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends