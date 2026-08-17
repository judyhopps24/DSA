class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n= nums.size();
        for(const auto& x: nums) sum+=x;
        if(sum%2!=0) return false;

        int target = sum / 2;
        vector<vector<bool>> dp( n , vector(target+1, false));
        
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }

        for(int i=0;i<=target;i++){
            dp[0][i]=false;
            if(nums[0] == i)
                dp[0][i]= true;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                if(j-nums[i] >= 0)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n-1][target];
    }

    // bool recurse(vector<int>& nums, int index, int subsetSum, int target, vector<vector<int>>& memo){

    //     if(subsetSum ==target)return true;
    //     if(index >= nums.size() || subsetSum>target) return false;

    //     if (memo[index][subsetSum] != -1) {
    //         return memo[index][subsetSum];
    //     }

    //     bool include =recurse(nums, index+1, subsetSum+ nums[index], target, memo);
    //     bool exclude = recurse(nums, index+1, subsetSum, target,memo);

    //     memo[index][subsetSum] = (include || exclude);
        
    //     return memo[index][subsetSum] ;
    // }
};
