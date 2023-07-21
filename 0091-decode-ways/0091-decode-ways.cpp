class Solution {
public:
    int solve(int i,int j,string &s,unordered_map <string,char> &mp,vector<vector<int>> &dp){
        //Reached to the END of the string. => Valid String 
        if(i>j) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        //var k: used for partitioning... eg: 11106 -> {1 1106} {11 106} {111 06} {1110 6}  
        for(int k=i;k<=j;k++){
            
            //After Partitioning, we will be checking Left Substring validity and 
            //no.of combinations of it with right Substring.
            //Eg: k=0 : LS = 1   RS = 1106.
            //num.of combinations of RS = [1 {1 106}] [1 {11 06}]  [1 {110 6}]. here only 2 are valid.
            // thus return 2. for partition k=1.

            //simiarly on next iteration, check for k = 2.... {11 106}. LS = 11   RS = 106.

            //this gives LS, LS is stored in curr.
            int currLen = (k-i) + 1;    
            string curr = (s.substr(i,currLen));

            //if LS is valid, then search for combinations of RS.
            if(mp.find(curr) != mp.end()){
                int count = solve(k+1,j,s,mp,dp);

                // (1&&count) -> if 1 : RS is Valid, if 0: RS is invalid (say, 06).
                //count = Num of Combs of RS.
                ans += (1&&count)*(count);
            }
        }

        //DP[i][j] => num of ways to decode, in substring starting with index i and ending with j.       
    return dp[i][j] = ans;
    }

    int numDecodings(string s) {
        int n = s.length();
        unordered_map <string,char> mp;


        //MAP for all the alphabets 
        int num = 1;
        for(char i = 'A'; i<= 'Z'; i++){
            string temp = to_string(num);
            mp[temp] = i;
            num++;
        }

        //DP Array.
        vector<vector<int>> dp(n, vector<int> (n, -1));

    return solve(0,n-1,s,mp,dp); 
    }
};