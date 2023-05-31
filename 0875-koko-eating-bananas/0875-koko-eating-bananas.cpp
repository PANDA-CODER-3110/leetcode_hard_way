class Solution {
public:

   bool can(int n, int h, int speed, vector<int>&piles){
       long long  int cnt=0;
        for (int i=0; i<n; i++){
            cnt+= (piles[i]/speed)+(piles[i]%speed!=0);
           
        }
        return (cnt<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
      int start=1; int end= 1e9;
        while(start<=end)
        {
            int m = (start+end)/2; 
            if(can(piles.size(),h,m,piles))
            {
                end= m -1  ; 
            }
            else
            {
                start = m+1 ; 
            }
        }
        return start; 
        
    }
};