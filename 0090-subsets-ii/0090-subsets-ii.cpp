class Solution {
public:
    void solve(vector<int>& nums , int id , set<vector<int>>&st, vector<int>&ps  )
    {
        if(id == nums.size())
        {
            st.insert(ps); 
            return ; 
        }
        ps.push_back(nums[id]); 
        solve(nums , id+1 , st, ps );
        ps.pop_back(); 
         solve(nums , id+1 , st, ps );
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans ; 
        vector<int>ps ; 
        sort(nums.begin(),nums.end()); 
        set<vector<int>>st ; 
        solve(nums , 0 , st , ps);
        for(auto it : st )
        {
            ans.push_back(it); 
        }
        return ans ; 
    }
};