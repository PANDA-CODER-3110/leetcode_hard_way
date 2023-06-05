class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int y,x;
        if(coordinates.size()==2)
        {
            return true;
        }
        for(int i=2;i<coordinates.size();i++)
        {
            y=coordinates[i][1];
            x=coordinates[i][0];
            if((y-coordinates[0][1])*(coordinates[1][0]-coordinates[0][0])!=((coordinates[1][1]-coordinates[0][1]))*(x-coordinates[0][0]))
            {
                return false;
            }
        }
        return true;
    }
};