class Solution {
public:
    void solve(int total , int ind , int n,int&cnt ){
        if(ind >n)
        {
            if(total==0)
             cnt++ ; 
            return ; 
        }
        for(int i=0 ; i<n;i++)
        {
            if(total&(1<<i)){
                if((i+1)%ind==0 || ind%(i+1)==0)
                    solve(total^(1<<i) ,ind+1 ,n ,cnt ) ; 

            }
        }
        
        
    }
    int countArrangement(int n) {
        int total = (1<<n) -1 ; 
        int cnt =0 ; 
        solve(total ,1 , n ,cnt) ;
         return cnt ; 
    }
};