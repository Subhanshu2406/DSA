vector<int> visited;
vector<int> topo;

void dfs(int src, vector<vector<pair<int,int>>>& adj){
    visited[src] = true;
    for(auto [nei, wt] : adj[src]){
        if(!visited[nei]){
            dfs(nei, adj);
        }
    }
    topo.push_back(src);
}

vector<int> shortestPathDAG(int V, int src, vector<vector<pair<int,int>>>& adj){
    visited.assign(V, 0);
    topo.clear();

    dfs(src, adj);
    reverse(topo.begin(), topo.end());

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int node : topo){
        if(dist[node] != INT_MAX){
            for(auto [nei, wt] : adj[node]){
                if(dist[node] + wt < dist[nei]){
                    dist[nei] = dist[node] + wt;
                }
            }
        }
    }

    return dist;
}
