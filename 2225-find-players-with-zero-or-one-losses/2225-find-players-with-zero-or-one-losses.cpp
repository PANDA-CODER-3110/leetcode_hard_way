class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int , int>v , l ;
        vector<int>a , b ; 
        vector<vector<int>>ans  ; 
        for(int i =0 ; i<matches.size() ; i++)
        {
           v[matches[i][0]]++ ; 
            l[matches[i][1]]++ ; 
        }
        
        for(auto it : v)
        {
            if(l[it.first]==0)
                a.push_back(it.first) ; 
          
        }
        for(auto it : l)
        {
            if(l[it.first]==1)
                b.push_back(it.first) ; 
          
        }
        
       ans.push_back(a) ; 
        ans.push_back(b) ; 
        return ans ; 
    }
};