class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        for(auto x:arr){
            m[x]++;
        }
        vector<pair<int,int>>vp;
        for(auto x:m){
            vp.push_back({x.second,x.first});
        }
        sort(vp.begin(),vp.end());
        int ans = 0;
        for(int i=0;i<vp.size();i++){
            if(k<vp[i].first){
                return vp.size()-i;
            }
            else if(k==vp[i].first){
                return vp.size()-i-1;
            }
            else{
                k = k - vp[i].first;
            }
        }
        return 0;
    }
};