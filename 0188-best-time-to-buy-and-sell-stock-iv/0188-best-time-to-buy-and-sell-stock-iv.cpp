class Solution {
public:
     int buyandsell(vector<int>& prices, int i, bool buy, int cap, vector<vector<vector<int>>> &dp)
    {
        if (i >= prices.size() || cap == 0)
            return 0;
        
        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        int leave = buyandsell(prices, i + 1, buy, cap, dp);
        if (buy)
        {
            int buying = buyandsell(prices, i + 1, !buy, cap, dp) - prices[i];
            dp[i][buy][cap] = max(buying, leave);
        } 
        else
        {
            int selling = buyandsell(prices, i + 1, !buy, cap - 1, dp) + prices[i];
            dp[i][buy][cap] = max(selling, leave);
        }
        return dp[i][buy][cap];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n, vector<vector<int>> (2, vector<int> (k + 1, -1)));
        return buyandsell(prices, 0, true, k, dp);
    }
};