class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==1)return 1;
        sort(points.begin(),points.end());
        int i=0,j=1;
        int prev = points[i][1];
        int count=0;
        while(j<points.size()){
            if(prev>=points[j][0]){
                prev = min(prev,points[j][1]);
                j++;
            }else{
                count++;
                i=j;
                prev = points[j][1];
                j++;
            }
        }
        if(i<j)count++;
        return count; 
    }
};