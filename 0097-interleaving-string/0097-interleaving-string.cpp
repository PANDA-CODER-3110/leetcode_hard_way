class Solution {
public:
     bool fun(int i,int j,int k,string s1,string s2,string s3,vector<vector<vector<int>>> &dp)
    {
        if ((i==s3.length()) && (j == s1.length()) && (k == s2.length()))
        {
            return true;
        }

        if ((i>s3.length()) || (j>s1.length()) || (k> s2.length()))
        {
            return false;
        }

        if (dp[i][j][k] != -1)
        {
            return dp[i][j][k];
        }

        if ((s3[i] == s1[j]))
        {
            if (fun(i+1,j+1,k,s1,s2,s3,dp))
            {
                return dp[i][j][k] = true;
            }
        }

        if ( (s3[i] == s2[k]))
        {
            if (fun(i+1,j,k+1,s1,s2,s3,dp))
            {
                return dp[i][j][k] = true;
            }
        }

        if ((s3[i] == s1[j]) && (s3[i] == s2[k]))
        {
            if (fun(i+1,j+1,k+1,s1,s2,s3,dp))
            {
                return dp[i][j][k] = true;
            }
        }

        return dp[i][j][k] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();

        vector<vector<vector<int>>> dp(n3+1,vector<vector<int>>(n1+1,vector<int>(n2+1,-1)));
        return fun(0,0,0,s1,s2,s3,dp);
    }
};