class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length(), m=word2.length();
        vector<vector<int>> memo(n, vector<int>(m,-1));
        return recurse(0,0,word1,word2, n,m,memo);
    }
    int recurse(int i , int j, string & s, string& t, int n, int m , vector<vector<int>> & memo){
        if(i == n)  return m-j;
        if (j== m) return n-i;

        if(memo[i][j] != -1)  return memo[i][j];


        if(s[i] == t[j]) return recurse(i+1, j+1, s,t, n,m, memo);


        // deleted i so move to next 
        // added in place of i so still need to match i
        int res = min(recurse(i+1, j,s,t,n,m,memo), recurse(i, j+1,s,t,n,m, memo));
        res =  1+ min(res, recurse(i+1, j+1,s,t,n,m, memo));

        memo[i][j] = res;
        return memo[i][j];
    }
};
