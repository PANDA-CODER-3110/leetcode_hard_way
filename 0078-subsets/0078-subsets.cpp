class Solution {
public:
    void solve(vector<int>& nums , vector<int>&pre ,vector<vector<int>>&ans , int ind , int n )
    {
        if(ind==n)
        {
           ans.push_back(pre) ; 
            return ; 
        }
        pre.push_back(nums[ind] ) ; 
        solve(nums , pre , ans , ind+1 , n) ; 
          pre.pop_back( ) ; 
        solve(nums , pre , ans , ind+1 , n) ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans ; 
        vector<int>pre ; 
        solve(nums ,pre , ans , 0  , nums.size()) ; 
        return ans ; 
    }
};