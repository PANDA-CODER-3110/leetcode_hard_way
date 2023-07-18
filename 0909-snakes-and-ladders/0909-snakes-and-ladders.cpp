class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> steps(n * n + 1, -1);
        vector<int>v;
        v.push_back(0);

        // flattening the board
        reverse(board.begin() , board.end());
        for(int i = 0 ;i<n;i++){
            if(i%2 == 0){
                for(int j = 0;j<n;j++){
                    v.push_back(board[i][j]);
                }
            }
            else{
                for(int j = n-1;j>=0;j--){
                    v.push_back(board[i][j]);
                }
            }
        }

        steps[1] = 0;
        queue<int> q;
        q.push(1);
        // simple bfs
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if (curr == n * n) {
                return steps[curr];
            }
            
            for (int i = 1; i <= 6; i++) {
                int next = curr + i;
                if (next > n * n) {
                    break;
                }
                if (v[next] != -1) {
                    next = v[next];
                }
                
                if (steps[next] == -1) {
                    steps[next] = steps[curr] + 1;
                    q.push(next);
                }
            }
        }
        
        return -1;
    }
};