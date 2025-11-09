class Solution {
public:
vector<bool> visited;
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        visited.resize(n,false);
        int res = 0;

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i = 0;i < n;i++){
            if(!visited[i]) {
                dfs(adj, i);
                res++;
            }
        }

        return res;
    }

    void dfs(vector<vector<int>>& adj, int i) {
        visited[i] = true;
        for(auto node : adj[i]) if(!visited[node]) dfs(adj, node);
        
        return;
    }   
};