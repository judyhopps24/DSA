class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int posSum = 0;
        

        for(int i=0;i<n;i++){
            posSum += nums[i];
        }

        // cout<<"size of vec"<<n<<" x "<< 2*posSum+1<<"\n";

        vector<vector<int>> dp(n, vector<int>(2*posSum+1, 0));

        for(int i= 0; i< 2*posSum+1 ;i++ ){
            int tar = i - posSum;
            // cout<<"i: "<<i<<" tar:  "<<tar<<" \n";
            if(nums[0] == tar)
                dp[0][i] += 1;
            if(-nums[0] == tar)
                dp[0][i] += 1;
        }

        // for(auto x: dp){
        //     for(auto y: x){
        //         cout<<y<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";

        for(int j=1;j<n;j++){
            for(int i=0; i< 2*posSum+1;i++){
                int tar = i - posSum; //-6


                int curr1 = nums[j]; //2
                int curr2 = nums[j]*-1; //-2

                int toLook1 = tar - curr1; //-8 or 
                int toLook2 = tar - curr2; // -4

                int toLookIndex1 = toLook1 + posSum; //-2
                int toLookIndex2 = toLook2 + posSum; // 10

                if(toLookIndex1 >= 0 && toLookIndex1< 2*posSum+1 )
                    dp[j][i] += dp[j-1][toLookIndex1];
                if(toLookIndex2 >= 0 && toLookIndex2< 2*posSum+1 )
                    dp[j][i] += dp[j-1][toLookIndex2];
            }
        }
        // for(auto x: dp){
        //     for(auto y: x){
        //         cout<<y<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";

        // cout<<target+posSum<<"\n";

        if (abs(target) > posSum) return 0;
        return dp[n-1][target+posSum];
    }
};
