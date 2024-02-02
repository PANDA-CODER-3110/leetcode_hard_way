class Solution {
public:
    int check(int start_digit, int len){
        int n=0;
        for(int i=1;i<=len;i++){
            n=n*10+start_digit;
            start_digit++;
        }
        return n;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        if(high<low)
            return res;
        int digit_start=log10(low)+1;
        int digit_end=log10(high)+1;
        int cnt=1;

        for(int i=digit_start;i<=digit_end;i++){
            for(int j=1;j<=10-i;j++){
                int num=check(j,i);
                if(num>=low && num<=high)
                    res.push_back(num);
            }
        }
        return res;
    }
};