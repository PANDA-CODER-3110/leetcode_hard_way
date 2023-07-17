class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string, vector<string>> map;
        vector<vector<string>> result;
        string s;

        for(auto str : strs) {
            s = str;
            sort(str.begin(), str.end());

            map[str].push_back(s);
        }

        for(auto it : map) {
            result.push_back(it.second);
        }

        return result;
    }
};