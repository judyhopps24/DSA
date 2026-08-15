class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, INT_MAX);
        distance[src]= 0;

        for(int i=0;i<k+1;i++){
            vector<int> tmp = distance;
            for(const auto& flight: flights){
                int u = flight[0];
                int v = flight[1];
                int d = flight[2];
                if(distance[u]!=INT_MAX &&  tmp[v] > distance[u] + d ){
                    tmp[v]= distance[u] + d;
                }
            }
            for(int j=0;j<n;j++){
                distance[j]= tmp[j];
            }
        }
        return distance[dst] ==INT_MAX ? -1: distance[dst];
    }
};
