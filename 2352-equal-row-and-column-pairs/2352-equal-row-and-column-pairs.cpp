class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
         map<vector<int>, int> r;
        map<vector<int>, int> c;
        for(auto i : grid) r[i]++;
        int rows = grid.size(), cols = grid.size();
        for(int i = 0; i < rows; i++){
            vector<int> temp;
            for(int j = 0; j < cols; j++){
                temp.push_back(grid[j][i]);
            }
            c[temp]++;
        }
        int ans = 0;
        for(auto i : r){
            if(c.count(i.first) > 0){
                ans += r[i.first] * c[i.first];
            }
        }
        return ans;
    }
};