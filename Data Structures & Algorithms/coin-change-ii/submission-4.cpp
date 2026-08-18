class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int s = 0;
        int n = coins.size();
        // vector<vector<int>> memo(n, vector<int>(amount, -1));
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                
                if (j - coins[i-1] >=0) {
                    dp[i][j] = dp[i-1][j]+ dp[i][j - coins[i-1]];
                } else {
                    dp[i][j] =  dp[i-1][j];
                }
            }
        }


        return dp[n][amount];
    }

    // int dfs(int index,vector<int>& coins, int s, int& amount ,vector<vector<int>>& memo ){
    //     if(s == amount) return 1;
    //     if(s>amount) return 0;
    //     if(index >= coins.size())  return 0;

    //     if(memo[index][s]!=-1) return memo[index][s];


    //     memo[index][s] = dfs(index +1, coins, s, amount, memo) + dfs(index, coins, s+coins[index], amount, memo);
    //     return memo[index][s];
    // }
};
