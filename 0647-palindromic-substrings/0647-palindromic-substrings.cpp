class Solution {
public:
    vector<vector<int>> dparray;
    int count(string &s,int startindex,int endindex){
        if(startindex>=endindex){
            return 1;
        }
        if(dparray[startindex][endindex]!=0){return dparray[startindex][endindex];}
        int left=0,right=0;
        if(s[startindex]==s[endindex]){
            left= count(s,startindex+1,endindex-1);
        }
        else{
            right=0;//count(s,startindex+1,endindex)+count(s,startindex,endindex-1);
        }
        return dparray[startindex][endindex]= left+right;

    }
    int countSubstrings(string s) {
        int n=s.size();
        dparray.resize(n, vector<int>(n, 0)); // Initialize the 2D vector
        int counts=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                counts+=count(s,i,j);
            }
        }
        return counts;
    }
};