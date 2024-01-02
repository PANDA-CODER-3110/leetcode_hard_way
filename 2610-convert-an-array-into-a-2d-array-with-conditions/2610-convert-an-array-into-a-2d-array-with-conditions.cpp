class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
          unordered_map<int, int>mp;
        for(int &a:nums) mp[a]++;
        vector<vector<int>>ans;
        while(!mp.empty()){
            vector<int>row, remove;
            for(auto &[ele, freq]:mp){
                row.push_back(ele);
                freq--;
                if(freq==0) remove.push_back(ele);
            }
            for (int &ele : remove) mp.erase(ele);
            ans.push_back(row);
        }
        return ans;
    }
};