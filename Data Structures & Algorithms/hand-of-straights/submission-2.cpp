class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        unordered_map<int,int> freq; 
        for(int i=0;i<n;i++){
                freq[hand[i]]++;
            }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto x: freq){
            if(x.second>0){
                pq.emplace(x.first);
            }
        }

        while(true){
            while(!pq.empty() && freq[pq.top()] == 0){
                pq.pop();
            }
            if(pq.empty()) return true; 
            int start = pq.top();
            for(int i=0;i<groupSize;i++){
                if(freq.find(start + i) != freq.end() && freq[start + i] > 0 ){
                    freq[start +i]--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
