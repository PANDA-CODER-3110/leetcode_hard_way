//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
   long long  int mergesort(long long arr[] , int left , int right,long long temp[])
    {
        if(left ==right  ) return 0 ; 
    long long int inv =0 ; 
        
            long long int mid = (left+right)/2 ; 
           inv+= mergesort(arr,left,mid,temp) ; 
            inv+=mergesort(arr,mid+1,right,temp); 
            inv+=merge(arr,temp,left ,mid+1, right); 
        
        return inv  ; 
    }
    
   long long  int merge(long long arr[],long long temp[] , int left , int mid , int high)
    {
        int i=0 , j=0 , k=0 ; 
     i=k = left ; 
     j = mid ; 
        long long  inv =0 ; 
        while(i<mid && j<=high)
        {
            if(arr[i]<=arr[j])
            temp[k++] = arr[i++] ; 
            else
            {
                temp[k++] = arr[j++] ; 
                inv+=(mid-i) ; 
                
            }
        }
        while(i<=mid-1)
        temp[k++] = arr[i++] ; 
        
        while(j<=high)
        temp[k++] = arr[j++]  ; 
        
        for(i= left;i<=high;i++)
        {
            arr[i] = temp[i]  ; 
        }
        return inv ; 
    }
    long long int inversionCount(long long arr[], long long N)
    { long long temp[N] ; 
       return mergesort(arr ,0 , N-1,temp);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends