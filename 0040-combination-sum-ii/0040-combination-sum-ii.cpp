 class Solution {
         void solve(vector<vector<int>>&ans ,vector<int>&temp ,vector<int> &A, int B , int ind  )
    {
        if(B==0)
        {
            ans.push_back(temp) ; 
            return  ; 
        }
        for(int i = ind ; i<A.size();i++)
        {
            if(i>ind && A[i]==A[i-1])
            continue ; 
            if(A[i]<=B)
            {
                temp.push_back(A[i]) ; 
                solve(ans , temp ,A , B - A[i], i+1) ; 
                temp.pop_back() ; 
            }
        }
        return ; 
    }
public:
    vector<vector<int>> combinationSum2(vector<int>&A, int B) {
          vector<vector<int>>ans ; 
        vector<int>temp ; 
        sort(A.begin(),A.end()) ; 
        solve(ans , temp , A , B , 0  ) ; 
        return ans ; 
    }
};