#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Function to perform BFS and find the k-th largest element
int kthLargestBFS(int startNode, const vector<vector<int>>& graph, const unordered_map<int, int>& values, int k) {
    int n = graph.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<bool> visited(n,false);
    pq.push(values[startNode]);
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while(!q.empty()){
        int node = q.top();
        for(int nei : graph[node]){
            if(!visited[nei]){
                pq.push(values[nei]);
                visited[nei] = true;
                q.push(nei);

                while(pq.size() > k) pq.pop();
            }
        }
    }

    return pq.top();
   
}

int main() {
    int n; // Number of vertices
    cin >> n;

    // Read the values of the vertices
    vector<int> vertexValues(n);
    for (int i = 0; i < n; ++i) {
        cin >> vertexValues[i];
    }

    // Sample graph as an adjacency list for a single component
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        graph[i].push_back(i + 1);
        graph[i + 1].push_back(i);
    }                           

    // Create a mapping of vertex indices to their values
    unordered_map<int, int> values;
    for (int i = 0; i < n; ++i) {
        values[i] = vertexValues[i];
    }

    // Read the value of k
    int k;
    cin >> k;

    // Starting BFS from the first node (0)
    int result = kthLargestBFS(0, graph, values, k);
    cout << result << endl;

    return 0;
}