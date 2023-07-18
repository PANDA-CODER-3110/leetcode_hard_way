class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
         // O(n^2) solution
        // calculate sloop of each point with each other
        // store in frequency map<slope,count>
        // keep track of running maxium
        int maxPoints = 0;        
        for (int i = 0; i < points.size(); i++) {
            unordered_map<double, int> slopes;
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                auto deltaY = points[j][1] - points[i][1];
                auto deltaX = points[j][0] - points[i][0];                
                auto slop = deltaY * 1.0 / deltaX;
                slopes[slop]++;                
                maxPoints = max(maxPoints, slopes[slop]);
            }
        }
        return maxPoints + 1;
    }
};