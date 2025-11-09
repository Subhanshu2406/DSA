class Solution {
public:
vector<int> visited;
vector<int> res;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> empty;      //to return this when no possible order possible
        int n = numCourses;

        for(auto edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }

        visited.resize(numCourses, -1);

        

        for(int i = 0;i < numCourses; i++){
            if(visited[i] == -1) {
                visited[i] = 0;     //means its in the dfs round now
                if(!dfs(adj, i)) return empty;
                visited[i] = 1;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(vector<vector<int>>& adj, int i){
        for(auto node : adj[i]){
            if(visited[node] == 0) return false;
            else if(visited[node] == -1){
                visited[node] = 0;
                if(!dfs(adj, node)) return false;
                visited[node] = 1;
            }
        }
        res.push_back(i);
        return true;
    }

};