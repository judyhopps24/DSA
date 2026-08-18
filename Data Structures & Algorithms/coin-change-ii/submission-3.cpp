class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int s = 0;
        int n = coins.size();
        vector<vector<int>> memo(n, vector<int>(amount, -1));
        return dfs(0, coins, 0, amount, memo);
    }

    int dfs(int index,vector<int>& coins, int s, int& amount ,vector<vector<int>>& memo ){
        if(s == amount) return 1;
        if(s>amount) return 0;
        if(index >= coins.size())  return 0;

        if(memo[index][s]!=-1) return memo[index][s];


        memo[index][s] = dfs(index +1, coins, s, amount, memo) + dfs(index, coins, s+coins[index], amount, memo);
        return memo[index][s];
    }
};
