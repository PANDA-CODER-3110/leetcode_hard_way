class Solution {
public:
    vector<vector<int>> ans;
    void combi(vector<int>& c, int idx, int t,vector<int> &v){
        if(t==0){
            ans.push_back(v);
            return;
        }
        if(idx==c.size()) return;

        if(c[idx]<=t){
          //we can pick
            v.push_back(c[idx]);
            combi(c,idx+1, t-c[idx],v);
            v.pop_back();  
        }
        
        int j=idx+1;
        while(j<c.size() and c[j]==c[j-1] ) j++;
        //we dont pick
        combi(c,j,t,v);

    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        ans.clear();
        sort(c.begin(),c.end());//for sorted order output
        vector<int> v;
        combi(c,0,target,v);
        return ans;
    }
};