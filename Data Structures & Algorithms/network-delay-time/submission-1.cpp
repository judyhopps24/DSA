class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int,vector<pair<int,int>>> m ;
        for(int i=0;i<times.size();i++){
            m[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        map<int, int> distance;
        for(int i=1;i<=n;i++){
            distance[i]=INT_MAX;
        }

        distance[k]=0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.emplace(0, k);

        while(!pq.empty()){
            auto [curr_dist, curr_node] = pq.top();
            pq.pop();
            if(curr_dist > distance[curr_node]) continue;

            for(const auto& neighbor: m[curr_node]){
                int next_node = neighbor.first;
                int weight = neighbor.second;
                if( distance[next_node] > curr_dist + weight) {
                    distance[next_node] = curr_dist + weight;
                    pq.emplace( distance[next_node], next_node);
                }
            }
        }

        int ans = 0;
        for(auto dis : distance){
            if(dis.second == INT_MAX) return -1;
            if(dis.first!=k)
                ans = max(ans, dis.second);
        }
        return ans;
    }
};
