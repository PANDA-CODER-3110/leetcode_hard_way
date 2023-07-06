//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  long long int solve(string s, int n,int k)
  {
      int i=0 , j=0 ; 
      long long int ans= 0 ; 
      long long int dist =0 ; 
      int hash[26] = {0}  ; 
      while(j<n)
      {
          hash[s[j]-'a']++ ; 
          if(hash[s[j]-'a']==1)
          dist++ ; 
          while(dist>k)
          {
              hash[s[i]-'a']-- ; 
              if(hash[s[i]-'a']==0)
              dist-- ; 
              i++ ; 
          }
          ans+=(j-i+1) ; 
          j++ ; 
      }
      return ans ; 
  }
    long long int substrCount (string s, int k) {
    int n = s.size() ; 
    return solve(s,n,k) - solve(s,n,k-1) ; 
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends