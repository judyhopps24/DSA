class Solution {
public:
    int climbStairs(int n) {
       
        int dp1 = 1;
        int dp2=1;
        int curr=1;
        for(int i=2;i<=n;i++){
            curr = dp1+dp2;
            dp2=dp1;
            dp1 = curr;

        }
        return curr;
    }
};
