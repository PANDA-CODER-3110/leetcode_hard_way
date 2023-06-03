class Solution {
public:
    vector<vector<int>>res ; 
    void solve(int ind , vector<int>&ans , vector<int>& nums , int n )
    {
        if(ind ==n)
        {
            res.push_back(ans) ;
            return ; 
        }
        ans.push_back(nums[ind]) ; 
        solve(ind+1 ,ans , nums, n) ;
         ans.pop_back() ; 
        solve(ind+1 ,ans , nums, n) ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans ; 
        solve(0 , ans , nums ,nums.size()) ; 
        return res ; 
    }
};