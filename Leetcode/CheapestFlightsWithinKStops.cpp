class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto flight : flights){
            adj[flight[0]].push_back({flight[1],flight[2]});    //storing node,cost
        }

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<>
        > pq;
        pq.push({0, src, 0});   //cost, node, step
        vector<vector<int>> dist(n, vector(k + 2, INT_MAX));
        dist[src][0] = 0;

        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();

            int cost  = get<0>(t);
            int node  = get<1>(t);
            int steps = get<2>(t);

            if(node == dst) continue;
            if(steps > k) continue;

            for(auto nei : adj[node]){
                int nextNode = nei.first;
                int weight = nei.second;

                if(dist[nextNode][steps + 1] > dist[node][steps] + weight){
                    dist[nextNode][steps + 1] = dist[node][steps] + weight;
                    pq.push({dist[node][steps] + weight, nextNode, steps + 1});
                }
            }
        }

        int res = INT_MAX;
        for(auto i : dist[dst]){
            res = min(res, i);
        }
        
        if(res == INT_MAX) return -1;
        return res;
    }
};