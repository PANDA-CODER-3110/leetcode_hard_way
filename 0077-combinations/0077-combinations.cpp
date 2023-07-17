class Solution {
public:
      void solve(int index, vector<vector<int>>& ans, int n, int k, vector<int>& a)
    {
        if(a.size()==k)
        {
            ans.push_back(a);
            return;
        }
        
        for(int j=index;j<=n;j++)
        {
            a.push_back(j);
            solve(j+1,ans,n,k,a);
            a.pop_back();
        }
    }
    
    
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        vector<int> a;
        solve(1,ans,n,k,a);
        return ans;
    }
};