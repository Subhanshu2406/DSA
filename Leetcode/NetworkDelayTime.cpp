class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);  //storing source : vector(target,length)
        for(auto time : times){
            adj[time[0]].push_back({time[1], time[2]});
        }

        vector<bool> visited(n+1, false);
        vector<int> dist(n+1, INT_MAX);


        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            function<bool(pair<int,int>, pair<int,int>)>
        > pq([](pair<int,int> a, pair<int,int> b) {
            return a.second > b.second;
        });
        pq.push({k,0});
        dist[k] = 0;

        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();

            int currNode = p.first;
            if(visited[currNode]) continue;
            visited[currNode] = true;
            int currDist = p.second;

            for(auto nodes : adj[currNode]){
                if(visited[nodes.first]) continue;
                if(dist[nodes.first] > nodes.second + dist[currNode]) {
                    pq.push({nodes.first, nodes.second + dist[currNode]});
                    dist[nodes.first] = nodes.second + dist[currNode];
                }
            }
        }

        int res = 0;
        for(int i = 1; i <= n;i++){
            if(visited[i] == false) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};