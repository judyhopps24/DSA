class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n,0);
        int sum = 0;

        prefix[0]= height[0];
        suffix[n-1] = height[n-1];
        for(int i=1;i<n;i++)
        {
            prefix[i] = max(prefix[i-1], height[i]);
        }

        // for(auto x: prefix) cout<<x<< " ";
        // cout<<"\n";


        for(int i=n-2;i>=0;i--)
        {
            suffix[i] = max(suffix[i+1], height[i]);
        }
        // for(auto x: suffix) cout<<x<< " ";
        // cout<<"\n";

        for(int i=1;i<n-1;i++){
            // cout<<"for index: "<<i<<" adding : "<<min(prefix[i-1], suffix[i+1]) - height[i]<<"\n";
            if(min(prefix[i-1], suffix[i+1]) - height[i] > 0)
                sum += min(prefix[i-1], suffix[i+1]) - height[i];
        }
        return sum;
    }
};
