class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n= nums.size();
        for(const auto& x: nums) sum+=x;
        if(sum%2!=0) return false;
        int target = sum / 2;
        vector<vector<int>> memo( n , vector(target+1, -1));

        return recurse(nums, 0, 0, sum/2, memo);
    }

    bool recurse(vector<int>& nums, int index, int subsetSum, int target, vector<vector<int>>& memo){

        if(subsetSum ==target)return true;
        if(index >= nums.size() || subsetSum>target) return false;

        if (memo[index][subsetSum] != -1) {
            return memo[index][subsetSum];
        }

        bool include =recurse(nums, index+1, subsetSum+ nums[index], target, memo);
        bool exclude = recurse(nums, index+1, subsetSum, target,memo);

        memo[index][subsetSum] = (include || exclude);
        
        return memo[index][subsetSum] ;
    }
};
