class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adjList(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x1 = points[i][0];
                int x2 = points[i][1];

                int y1 = points[j][0];
                int y2 = points[j][1];

                int mahHattanDist = abs(x1-y1) + abs(x2-y2);

                adjList[i].push_back({j, mahHattanDist});
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        set<int> visited;
        int cost=0;

        pq.emplace(0, 0);
        while(visited.size()!=n){
            if(pq.empty()) break;

            auto [curr_dis, curr_node] = pq.top();
            pq.pop();
            if(visited.contains(curr_node)) continue;

            visited.insert(curr_node);
            cost+= curr_dis;

            for(const auto& next: adjList[curr_node]){
                int next_dis = next.second;
                int next_node = next.first;
                if(!visited.contains(next_node))
                    pq.emplace(next_dis, next_node);
            }
        }
        return cost;
    }
};
