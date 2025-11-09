#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// DFS function to calculate the sum of values greater than the threshold
void dfs(int node, const vector<vector<int>>& graph, const vector<int>& values, int threshold, int& sum, unordered_set<int>& visited) {
    
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

    // Read the threshold value
    int threshold;
    cin >> threshold;

    // To keep track of visited nodes and the sum
    unordered_set<int> visited;
    int sum = 0;

    // Start DFS from the first node (0)
    dfs(0, graph, vertexValues, threshold, sum, visited);

    // Output the result
    cout << sum << endl;

    return 0;
}