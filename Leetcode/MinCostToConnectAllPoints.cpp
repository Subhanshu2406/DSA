//this is an n^2 log(n) solution
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int cost = 0;
        int n = points.size();
        vector<bool> visited(n, false);

        priority_queue<pair<int,int>, vector<pair<int,int>, greater<pair<int,int>>> heap;
        heap.push({0,0});

        while(!heap.empty()){
            int vertex = heap.top().second;
            int tempCost = heap.top().first;
            heap.pop();

            if(visited[vertex]) continue;
            visited[vertex] = true;
            cost += tempCost;
            
            for(int i = 0;i < n; i++){
                if(i == vertex || visited[i]) continue;
                int dist = abs(points[vertex][0] - points[i][0]) + abs(points[vertex][1] - points[i][1]);
                heap.push({dist, i});
            }
        }

        return cost;
    }
};