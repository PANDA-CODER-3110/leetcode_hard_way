class Solution {
public:
    int longestString(int x, int y, int z) {
          return 2*z+2*(x!=y?min(x,y)+1:x)+2*min(x,y);
    }
};