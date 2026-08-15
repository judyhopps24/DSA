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
            pair<int,int> tmp = pq.top();
            pq.pop();

            for(auto node: m[tmp.second]){
                if( distance[node.first] > distance[tmp.second] + node.second) {
                    distance[node.first] =distance[tmp.second] + node.second;
                    pq.emplace(distance[node.first], node.first);
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
