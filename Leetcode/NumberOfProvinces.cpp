class Solution {
public:
vector<bool> visited;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        vector<vector<int>> adj(n);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(isConnected[i][j] == 1) adj[i].push_back(j);
            }
        }

        int res = 0;
        visited.resize(n, false);

        for(int i = 0; i < n;i++){
            if(!visisted[i]) {
                dfs(adj, i);
                res++;
            }
        }

        return res;
    }

    void dfs(vector<vector<int>>& adj, int i){
        visited[i] = true;
        for(edge : adj[i]){
            if(!visited[edge]) dfs((adj, edge));
        }
        return ;
    }
};