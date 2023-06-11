class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
          int five=0;
        int ten=0;
        int N = bills.size() ; 
        for(int i=0;i<N;i++){
            int change=bills[i]-5;
            if(bills[i]==5) five++;
            if(bills[i]==10) ten++;
            if(change==0) continue;
            
            if(change==5) {
                if(five>0) {
                    five--;
                }
                else{
                    return false;
                }
            }
            
            if(change==15){
                if(ten>=1&&five>=1){
                    ten--;
                    five--;
                }
                else if(five>=3){
                    five-=3;
                }
                else return false;
            }
            
        }
        return true;
    }
};