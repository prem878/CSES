#include <iostream>
#include <vector>
using namespace std;
 
vector<int> parent;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> cycle;
 
bool dfs(int u) {
    vis[u] = true;
 
    for (int v : adj[u]) {
        if (!vis[v]) {
            parent[v] = u;
            if (dfs(v)) return true;
        } else if (v != parent[u]) {
            // Cycle detected
            int curr = u;
            while (curr != v) {
                cycle.push_back(curr);
                curr = parent[curr];
            }
            cycle.push_back(v);
            cycle.push_back(u);
            return true;
        }
    }
    return false;
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    adj.resize(n + 1);
    parent.resize(n + 1, -1);
    vis.resize(n + 1, false);
 
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    // Find a cycle
    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && dfs(i)) break;
    }
 
    if (cycle.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << cycle.size()  << "\n";
        for (int it : cycle) {
            cout << it << " ";
        }
        cout << "\n";
    }
 
    return 0;
}
