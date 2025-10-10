class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> graph(n + 1);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);  
            graph[e[1]].push_back(e[0]);   
        }
        vector<int> visited(n + 1, 0);

        return dfs(n,graph,t,target,1,1,visited);      //initial vertex is 1
    }

    double dfs(int n, vector<vector<int>>& graph, int t, int target, int num, double prob,vector<int>& visited){
        visited[num] = 1;
        int multiplier = 0;
        for(int test : graph[num]){
            if(!visited[test]) multiplier ++;
        }

        if(t < 0) return 0;
        if(num == target){
            if(t == 0) return prob;
            else if(multiplier) return 0;
            else return prob;
        }

        for (int nei : graph[num]) {
            if (!visited[nei]) {
                double res = dfs(n, graph, t - 1, target, nei, prob / multiplier, visited);
                if (res > 0) return res;
            }
        }
        return 0;
    }
};