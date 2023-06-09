//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
     vector<char>freq(256,0);        
        int n = s.length(), st = 0, end = 0, ans = 0;		
        while(end < n){            
            freq[s[end]]++;            
            while(freq[s[end]] != 1){
                freq[s[st]]--;
                st++;
            }            
            ans = max(ans, end - st + 1);
            end++;                   
        }        
        return ans;  
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends