class Solution {
public:
    void solve(vector<int>& c, int t , int s ,vector<int>&ps,vector<vector<int>>&ans, int id  )
    {
        if(id>=c.size() || s>t)
            return ; 
        if(s==t)
        {
            ans.push_back(ps); 
            return ; 
        }
        ps.push_back(c[id]) ; 
        s+=c[id]; 
        solve(c,t,s,ps,ans,id); 
        ps.pop_back(); 
        s-=c[id] ; 
        solve(c,t,s,ps,ans,id+1); 
        
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
      int sum =0 ; 
        vector<int>ps;vector<vector<int>>ans; 
        sort(c.begin(),c.end()); 
        solve(c , target, 0 , ps , ans , 0 ) ; 
        return ans ; 
        
    }
};