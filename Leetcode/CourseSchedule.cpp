class Solution {
public:
vector<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }

        visited.resize(numCourses, 0);

        for(int i = 0; i < numCourses; i++){
            if(visited[i] != 1 && dfs(i,visited,adj)) return false;
        }

        return true;
    }

    bool dfs(int node, vector<int>& visited, vector<vector<int>>& adj){
        if(visited[node] == 2) return true;  //base
        if(visited[node] == 1) return false; //dfs already perfomred via this node
        visited[node] = 2;

        for(int i = 0;i < adj[node].size() ;i++){
            if(dfs(adj[node][i], visited, adj)) return true;
        }
        visited[node] = 1;

        return false;
    }

};