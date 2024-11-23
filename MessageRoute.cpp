#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // for reverse
#include <limits.h> // for INT_MAX
 
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
 
    // Reading the graph
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    vector<int> dis(n + 1, INT_MAX); // Initialize distances with infinity
    vector<int> parent(n + 1, -1);
    int src = 1;
    int des = n;
    queue<int> q;
 
    dis[src] = 0; // Starting point
 
    q.push(src);
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v : adj[u]) {
            if (dis[u] + 1 < dis[v]) {
                dis[v] = dis[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
 
    // Check if there is a path from src to des
    if (dis[des] == INT_MAX) {
        cout << "IMPOSSIBLE";
    } else {
        // Reconstruct the shortest path using the parent array
        vector<int> shortest_path;
        int current = des;
        while (current != -1) {
            shortest_path.push_back(current);
            current = parent[current];
        }
 
        // Reverse the path to print it from src to des
        reverse(shortest_path.begin(), shortest_path.end());
 
        // Output the shortest path
        cout << shortest_path.size()  << "\n"; // Number of edges in the path
        for (int i = 0; i < shortest_path.size(); ++i) {
            cout << shortest_path[i];
            if (i != shortest_path.size() - 1) {
                cout << " ";
            }
        }
    }
 
    return 0;
}
