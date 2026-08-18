class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int r = 0;
        int l = 0;

        priority_queue<pair<int,int>> pq;
        vector<int> ans;

    
        while(r<n){
            // cout<<"l: "<<l<<" r: "<<r<<'\n';
            pq.emplace(nums[r],r);
            // cout<<"pushing "<<nums[r]<<" "<<r<<"\n";            
            pair<int,int> temp = pq.top();
                     
            int max_ind = temp.second;
            int max_num = temp.first;
            // cout<<"temp: "<<max_num<<" "<<max_ind<<"\n";   

            if(r-l+1 ==k){
                // cout<<"length is k\n";   
                while(!(max_ind >= l && max_ind<=r) ){
                    // cout<<"max_ind is not within "<<l<<" "<<r<<"\n";   
                    pq.pop();
                    temp = pq.top();
                    // cout<<"getting next big num\n";   
                    max_ind = temp.second;
                    max_num = temp.first;
                    // cout<<"temp updated: "<<max_num<<" "<<max_ind<<"\n";   
                }
                // cout<<"found!: "<<max_num<<" "<<max_ind<<"\n";   
                ans.push_back(max_num);
                l++;
            }
            
            //reduce the window
            
            
            // increase r
            r++;
        }
        return ans;
    }
};
