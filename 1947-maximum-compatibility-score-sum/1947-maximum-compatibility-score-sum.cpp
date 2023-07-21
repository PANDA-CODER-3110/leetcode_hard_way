class Solution {
public:
    int solve2(vector<int>&v1 , vector<int>v2)
    {
        int ans =0 ; 
        for(int i=0 ; i<v1.size();i++)
        {
            if(v1[i]==v2[i])
                ans++ ; 
        }
        return ans ; 
    }
void solve(int ind ,vector<vector<int>>& students, vector<vector<int>>& mentors , int bit , int cnt , int &ans ){
    int n = mentors.size() ; 
    if(bit ==0 || ind==n)
    {
        ans = max(ans , cnt) ; 
        return ; 
    }
    for(int i=0 ; i<n;i++)
    {
        if(bit&(1<<i)){
            int temp = solve2(students[ind] ,mentors[i]) ; 
            solve(ind+1 , students , mentors , bit^(1<<i), cnt+temp , ans) ; 
        }
    }
}
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
     int n = mentors.size() ; 
        int bitmask = (1<<n)-1 ; 
        int ans =0 , cnt=0 ; 
        solve(0 , students , mentors , bitmask, cnt , ans) ; 
        return ans ; 
    }
};