class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int> ans;

        auto comp = [](pair<int,int> a, pair<int,int> b){
            return a.first > b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        for(auto x: m){
            pq.emplace(x.second, x.first);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};
