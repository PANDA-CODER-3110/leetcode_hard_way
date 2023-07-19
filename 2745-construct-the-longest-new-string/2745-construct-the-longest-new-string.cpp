class Solution {
public:
    int longestString(int x, int y, int z) {
          int AAStart = 0;
        int BBStart = 0;
        while(x>0 && y>0){
            AAStart+=2;
            BBStart+=2;
            x--;
            y--;
        }
        if(x>0){
            AAStart++;
        }
        if(y>0){
            BBStart++;
        }
        int ans = max(AAStart,BBStart);
        ans += z;
        return ans*2;
    }
};