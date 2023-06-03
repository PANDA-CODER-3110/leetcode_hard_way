//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void combinationSum2(vector<int>& candidates, int target, vector<vector<int>> &output, vector<int> &temp, int index){
        if(target < 0){
            return;
        }
        else if(target == 0){
            output.push_back(temp);
        }
        else{
            for(int i=index; i<candidates.size(); i++){
                if(i>index && candidates[i] == candidates[i-1]){
                    continue;
                }
                temp.push_back(candidates[i]);
                combinationSum2(candidates, target-candidates[i], output, temp, i+1);
                temp.pop_back();
            }
        }
    }
     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> output;
        vector<int> temp;
        combinationSum2(candidates, target, output, temp, 0);
        return output;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends