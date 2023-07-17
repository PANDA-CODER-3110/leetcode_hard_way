class Solution {
void backtracking(int &n, int &k, vector<int>& currentPath, vector<vector<int>> &allPaths, unordered_set<int> &visited) {
        // base case
        if(currentPath.size() == k) {
            allPaths.push_back(currentPath);
            return;
        }

        // start backtracking
        for(int i = currentPath.empty() ? 1 : currentPath.back() + 1; i <= n; i++) {
            if(visited.find(i)!=visited.end()) continue;
            visited.insert(i);
            currentPath.push_back(i);
            backtracking(n, k, currentPath, allPaths, visited);
            visited.erase(i);
            currentPath.pop_back();
        }
    } 
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> currentPath;
        vector<vector<int>> result;
        unordered_set<int> visited;
        backtracking(n, k, currentPath, result, visited);
        return result;
    }
};