class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(n, vector<int>(2, 0));


        // dp[i][0] = Max profit at the end of day i given that you do not own any stock right now.
        // dp[i][1] = Max profit at the end of day i given that you currently own a stock right now.

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        dp[1][0] = max(dp[0][1] + prices[1] , dp[1][0]);
        dp[1][1] = max(-prices[1], dp[0][1]);

        for(int i=2;i<n;i++){
            // either do nothing. or sell the stock I owned on the prev day
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]); //can only buy on i if sold on i-2 or before


            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i] );
        }
        return max(dp[n-1][0], dp[n-1][1]);
        
    }
};
