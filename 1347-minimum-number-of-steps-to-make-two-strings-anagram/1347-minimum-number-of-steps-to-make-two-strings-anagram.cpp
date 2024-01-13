class Solution {
public:
    int minSteps(string s, string t) {
          vector<int> hashS(27, 0);
       vector<int> hashT(27, 0);

       for(auto i:s){
           hashS[i-'a']++;
       }
       for(auto i:t){
           hashT[i-'a']++;
       }

        int cnt=0;

        for(int i=0; i<27; i++)
        {
            if(hashT[i] > hashS[i])
                cnt = cnt+hashT[i]-hashS[i];
        }

        return cnt;
    
    }
};