class Solution {
public:
    int search(vector<int>&A, int target) {
        int l = 0 , h = A.size()-1 ; 
        int key= target ; 
          while(l<=h)
      {
          int m = (l+h)/2; 
          if(A[m]==key) return m ;  
          else if(A[l]<=A[m])
          {
              if(A[l]<=key && key<=A[m])
              {
                  h = m-1 ; 
              }
              else
              l= m+1  ; 
          }
          else
          {
              if(A[m]<=key && key<=A[h])
              {
                  l = m+1 ; 
              }
              else
             h = m-1 ; 
          }
      }
      return - 1; 
    }
};