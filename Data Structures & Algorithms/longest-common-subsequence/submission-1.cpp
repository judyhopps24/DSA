class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(), m=text2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //dp[i][j] denote the lcs by that can be formed with the first i chars from t1 and first j chars from t2
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] +1;
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            }
        }
        // for(auto y: dp){
        //     for(auto x: y){
        //         cout<<x<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";

        return dp[n][m];

    }
};
