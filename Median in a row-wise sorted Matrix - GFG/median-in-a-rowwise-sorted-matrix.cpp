//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int cntsum(vector<int>row , int value)
{
    int low = 0 , high = row.size() -1 ; 
    while(low<=high)
    {
        int mid = (low+high)/2 ;
         if(row[mid]<=value)
         low = mid+1 ; 
         else high = mid -1 ; 
    }
    return low ; 
}
    int median(vector<vector<int>> &matrix, int R, int C){
        int lo = 1 , hi = 1e9   ; 
        while(lo<=hi)
        {
            int mid = (lo+hi)/2 ; 
            int cnt =0 ; 
            for(int i=0 ;i<R;i++)
            {
                cnt+=cntsum(matrix[i] , mid) ;
            }
            
            if(cnt<=(R*C)/2)lo = mid+1 ; 
            else
            hi = mid -1 ; 
        }
        return lo ; 
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends