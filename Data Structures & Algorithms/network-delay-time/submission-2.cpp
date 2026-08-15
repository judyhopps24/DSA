class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1. Use vector instead of map for fast O(1) lookups
        vector<vector<pair<int, int>>> adj(n + 1);
        for(const auto& time : times){
            adj[time[0]].push_back({time[1], time[2]});
        }
        
        // 2. Initialize distance vector
        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;

        // Min-heap: stores {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.emplace(0, k);

        while(!pq.empty()){
            auto [curr_dist, curr_node] = pq.top();
            pq.pop();

            // 3. The Visited/Stale Check: Skip if we already processed a shorter path
            if (curr_dist > distance[curr_node]) continue;

            for(const auto& neighbor : adj[curr_node]){
                int next_node = neighbor.first;
                int weight = neighbor.second;
                
                // 4. Update weight (Relaxation)
                if(distance[next_node] > curr_dist + weight) {
                    distance[next_node] = curr_dist + weight;
                    pq.emplace(distance[next_node], next_node);
                }
            }
        }

        // 5. Find the maximum time taken
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(distance[i] == INT_MAX) return -1;
            ans = max(ans, distance[i]);
        }
        return ans;
    }
};
