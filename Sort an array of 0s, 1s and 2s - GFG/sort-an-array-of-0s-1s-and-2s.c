// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C
void sort012(int a[], int n)
{
    int j=0 ; 
    int k = n-1 ; 
    for(int i=0 ;i<=k;i++)
    {
        if(a[i]==0)
        {
           int temp = a[j] ; 
          a[j] = a[i]  ; 
          a[i] = temp ; 
          j++ ; 
           
        }
        else if(a[i] == 2)
        {
            int temp = a[k] ; 
          a[k] = a[i]  ; 
          a[i] = temp ; 
          k-- ; 
          i-- ; 
        }
    }
}

// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends