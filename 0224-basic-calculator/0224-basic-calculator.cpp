class Solution {
public:
    int calculate(string s) {
          int sum = 0, sign = 1;
        stack<pair<int, int>> prv;
        for(int i = 0; i < s.length(); i++){
            int curr = 0;
            if(s[i] == ' ') continue;
            if(s[i] >= '0' && s[i] <= '9'){
                while(s[i] >= '0' && s[i] <= '9' && i < s.length()){
                    curr = curr*10+(s[i]-'0');
                    i++; } 
                i--;
                sum += (curr*sign);
                sign = 1;
            }
            else if(s[i] == '('){
                prv.push({sum, sign});
                sum = 0; sign = 1;
            }
            else if(s[i] == ')'){
                sum = prv.top().first + (sum*prv.top().second);
                prv.pop();
            }
            else if(s[i] == '-') sign = -1;
        }
        return sum;
    } 
};