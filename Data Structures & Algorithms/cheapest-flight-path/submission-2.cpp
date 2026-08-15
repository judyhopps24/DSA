class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(const auto& flight: flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<vector<int>> distance(n, vector<int>(k+2, INT_MAX));

        distance[src][0] = 0;

       
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        pq.emplace( 0, 0, src);

        while(!pq.empty()){
            auto [curr_weight, stops, curr_node] = pq.top();
            pq.pop();
            if(curr_weight > distance[curr_node][stops]) continue;
            if(stops > k) continue;

            for(const auto& next: adj[curr_node]){
                int next_node = next.first;
                int dist_to_next = next.second;

                if(distance[next_node][stops+1] > curr_weight + dist_to_next){
                    distance[next_node][stops+1] = curr_weight + dist_to_next;
                    pq.emplace(distance[next_node][stops+1], stops+1, next_node);
                }
            }

        }

        int min_price = INT_MAX;
        for (int i = 0; i <= k + 1; ++i) {
            min_price = min(min_price, distance[dst][i]);
        }
        return min_price == INT_MAX ? -1 : min_price;

    }
};
