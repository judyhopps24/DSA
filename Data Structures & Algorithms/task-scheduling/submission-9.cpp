class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>freq;
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]]++;
        }
        int globalTime = 1;
        priority_queue<pair<int, char>> pq;
        for(auto x: freq){
            if(x.second != 0){
                pq.emplace(x.second, x.first);
            }
        }
        queue<pair<char, int>> waitTimeQueue;
        while(!waitTimeQueue.empty() || !pq.empty()){
            if(!waitTimeQueue.empty()){
                pair<char, int> waitQTop = waitTimeQueue.front();
                if(waitQTop.second <= globalTime){
                    waitTimeQueue.pop();
                    pq.emplace(freq[waitQTop.first], waitQTop.first);
                } 
            }
            if(!pq.empty()){
                pair<int, char> top = pq.top();
                pq.pop();
                freq[top.second]--;
                if(freq[top.second]!=0){
                    waitTimeQueue.emplace(top.second, globalTime+n+1);
                }  
            }
             globalTime++;
        }
        return globalTime-1;
    }
};
