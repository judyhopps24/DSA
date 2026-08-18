class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length(), m=word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

        //dp i j  denoted number of operations to make first i chars of word1 == first j chars of word2
        dp[0][0]= 0;
        for(int i=1;i<=n;i++){
            if(word1[i-1] == word2[0])
                dp[i][0] = dp[i-1][0];
            else
                dp[i][0] = 1+dp[i-1][0];
        }
        for(int j=1;j<=m;j++){
            if(word1[0] == word2[j-1])
                dp[0][j] = dp[0][j-1];
            else
                dp[0][j] = 1+dp[0][j-1];
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]) +1;
                }
            }
        }
        return dp[n][m];
    }
    // int recurse(int i , int j, string & s, string& t, int n, int m , vector<vector<int>> & memo){
    //     if(i == n)  return m-j;
    //     if (j== m) return n-i;

    //     if(memo[i][j] != -1)  return memo[i][j];


    //     if(s[i] == t[j]) return recurse(i+1, j+1, s,t, n,m, memo);


    //     // deleted i so move to next 
    //     // added in place of i so still need to match i
    //     int res = min(recurse(i+1, j,s,t,n,m,memo), recurse(i, j+1,s,t,n,m, memo));
    //     res =  1+ min(res, recurse(i+1, j+1,s,t,n,m, memo));

    //     memo[i][j] = res;
    //     return memo[i][j];
    // }
};
