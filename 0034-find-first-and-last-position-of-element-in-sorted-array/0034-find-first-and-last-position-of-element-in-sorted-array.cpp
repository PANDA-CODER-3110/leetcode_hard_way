class Solution {
public:
    vector<int> searchRange(vector<int>& n, int x) {
      int s = lower_bound(begin(n) , end(n) , x) - begin(n) ;
        int e = lower_bound(begin(n) , end(n) , x+1) - begin(n) ;
        if(s<n.size() && n[s]==x)
             return {s,e-1} ; 
        return {-1,-1} ; 
        
    }
    
};