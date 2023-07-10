//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
       long long int left =0 , right = n-1 , left_max = 0 , right_max = 0 , ans =0 ; 
       while(left<=right)
       {
           if(arr[left]<arr[right])
           {
               if(arr[left]>left_max){
                   left_max =arr[left] ;  
               }
               else
               {
                   ans+=left_max - arr[left] ; 
               }
               left++ ; 
           }
           else
           {
               if(arr[right]>right_max){
                   right_max =arr[right] ;  
               }
               else
               {
                   ans+=right_max - arr[right] ; 
               }
               right-- ; 
           }
           
       }
       return ans ; 
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends