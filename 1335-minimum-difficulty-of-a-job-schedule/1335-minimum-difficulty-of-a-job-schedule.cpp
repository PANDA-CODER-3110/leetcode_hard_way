class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if (n < d)
            return -1;

        vector<vector<int>> t(n+1, vector<int>(d+1, -1));
        //t[i][j] = minimum diffculty of doing job from index i to n-1 in j days.

        // Base case: if there is only one day - Do all jobs on that day
        for (int i = 0; i < n; i++) {
            t[i][1] = *max_element(begin(jobDifficulty) + i, end(jobDifficulty));
        }

        // Build the DP table bottom-up
        for (int days = 2; days <= d; days++) {
            for (int i = 0; i <= n - days; i++) {
                int maxDifficulty = INT_MIN;
                int result        = INT_MAX;

                for (int j = i; j <= n - days; j++) {
                    maxDifficulty   = max(maxDifficulty, jobDifficulty[j]);
                    result          = min(result, maxDifficulty + t[j + 1][days - 1]);
                }

                t[i][days] = result;
            }
        }

        return t[0][d];
    }
};