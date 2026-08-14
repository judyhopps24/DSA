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
                // cout<<" wait list is not epmty \n";
                pair<char, int> waitQTop = waitTimeQueue.front();
                //  cout<<"waitQTop : "<< waitQTop.first<<" "<<waitQTop.second<<"\n";
                if(waitQTop.second <= globalTime){
                    // cout<<"waitQTop is ready: \n";
                    waitTimeQueue.pop();
                    // cout<<" puhsing to pq\n";
                    pq.emplace(freq[waitQTop.first], waitQTop.first);
                } 
            }

            if(!pq.empty()){
                
                // cout<<"pq is not empty\n";
                pair<int, char> top = pq.top();
                // cout<<"pq top :"<<top.second<<" : fre: "<<top.first<<"\n";
                pq.pop();

                freq[top.second]--;
                // cout<<" reducing freq \n";
                if(freq[top.second]!=0){
                    // cout<<"freq is not 0 adding to waitList \n";
                    waitTimeQueue.emplace(top.second, globalTime+n+1);
                }  
            }
             globalTime++;
                
        }

        return globalTime-1;

    }
};
