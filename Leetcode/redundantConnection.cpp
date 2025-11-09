class Solution {
public:
vector<int> visited;
unordered_set<int> cycle;

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        visited.resize(n + 1, 0);
        vector<vector<int>> adj(n + 1);

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        stack<int> stk;
        dfs(adj, stk, 1, 0);

        for(int i = n - 1; i >=0 ;i--){
            if(cycle.find(edges[i][0]) != cycle.end() && cycle.find(edges[i][1]) != cycle.end()) return edges[i];
        }

        return {};

    }

    bool dfs(vector<vector<int>>& adj, stack<int>& stk, int i, int parent){
        stk.push(i);
        visited[i] = 1;

        for(auto node : adj[i]){
            if(node == parent) continue;

            else if(visited[node] == 0 && dfs(adj, stk, node, i)) return true;

            else if(visited[node] == 1) {
                vector<int> temp;
                while(!stk.empty()) {
                    int curr = stk.top();
                    temp.push_back(curr);
                    stk.pop();
                    if(curr == node) break;
                }
                for(int t : temp) cycle.insert(t);
                return true;
            }
        }

        stk.pop();
        visited[i] = 2;
        return false;
    }
};