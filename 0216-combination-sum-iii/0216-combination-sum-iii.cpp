class Solution {
public:
     vector<vector<int>>ans;
     void combi(vector<int>& c, int idx, int t,vector<int> &v , int k  ){
        if(t==0 && v.size()==k){
            ans.push_back(v);
            return;
        }
        if(idx==c.size()) return;

        if(c[idx]<=t){
          //we can pick
            v.push_back(c[idx]);
            combi(c,idx+1, t-c[idx],v ,  k );
            v.pop_back();  
        }
        
        int j=idx+1;
        while(j<c.size() and c[j]==c[j-1] ) j++;
        //we dont pick
        combi(c,j,t,v , k );

    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
         vector<int>A;
        for(int i=1;i<10;i++){
            A.push_back(i);
        }
         vector<int>temp;
            combi(A,0,n,temp , k  );
        return ans ;
    }
};