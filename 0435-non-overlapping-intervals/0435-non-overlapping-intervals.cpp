class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int N = intervals.size() ; 
        sort(intervals.begin(),intervals.end());
        int end = intervals[0][1] ;
        int count = 0 ;
        for(int i=1 ; i<N ; i++)
        {
            if(intervals[i][0] >= end)
            {
                end = intervals[i][1] ;
            }
            else
            {
                end = min(end,intervals[i][1]);
                count++ ;
            }
        }
        return count;
    }
};