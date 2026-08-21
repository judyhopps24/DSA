class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> subset;
        recurse(nums, 0, n, ans, subset);
        return ans;
    }
    void recurse(vector<int>& nums, int i,  int n, vector<vector<int>>& ans,  vector<int>& subset){
        if(i>=n)
        {
            ans.push_back(subset);
            return;
        }

        recurse(nums, i+1, n, ans, subset);
        

        subset.push_back(nums[i]);
        recurse(nums, i+1,n,ans, subset);
        subset.pop_back(); 
    }
};




