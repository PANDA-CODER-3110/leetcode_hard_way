class Solution {
public:
  void solve(vector<vector<int>>&ans ,vector<int>&temp ,vector<int> &A, int B , int ind  )
    {
        if(ind==A.size())
        {
            if(B==0)
            ans.push_back(temp) ; 
            return  ; 
        }
       
            if(A[ind]<=B)
            {
                temp.push_back(A[ind]) ; 
                solve(ans , temp ,A , B - A[ind], ind) ; 
                temp.pop_back() ; 
            }
      
       solve(ans , temp , A , B , ind+1 ) ; 
    }
    vector<vector<int>> combinationSum(vector<int>& A, int B) {
     vector<vector<int>>ans ; 
        vector<int>temp ; 
        sort(A.begin(),A.end()) ; 
        A.erase(unique(A.begin(),A.end()) , A.end()) ; 
        solve(ans , temp , A , B , 0  ) ; 
        return ans ; 
        
    }
};