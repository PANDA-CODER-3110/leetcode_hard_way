class Solution {
public:
  void solve(vector<vector<int>>&ans ,vector<int>&temp ,vector<int> &A, int B , int ind  )
    {
        if(B==0)
        {
            ans.push_back(temp) ; 
            return  ; 
        }
        for(int i = ind ; i<A.size();i++)
        {
            if(A[i]<=B)
            {
                temp.push_back(A[i]) ; 
                solve(ans , temp ,A , B - A[i], i) ; 
                temp.pop_back() ; 
            }
        }
        return ; 
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