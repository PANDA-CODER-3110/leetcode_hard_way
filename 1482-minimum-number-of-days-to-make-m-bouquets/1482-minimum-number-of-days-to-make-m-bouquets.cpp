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
    int minDays(vector<int>& bloomDay, int m, int k) {
       // sort(bloomDay.begin(),bloomDay.end());
        int start = 0 , end = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = INT_MAX;
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