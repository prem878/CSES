#include <bits/stdc++.h>
using namespace std;

#define pb push_back

// Global data structures
unordered_map<int, vector<int>> graph;
unordered_map<int, int> nodeIndex;   // Renamed from 'index' to 'nodeIndex'
unordered_map<int, int> lowlink;
stack<int> S;
set<int> onStack;
vector<vector<int>> sccs;
int idx = 0;

void tarjanDFS(int node) {
    nodeIndex[node] = lowlink[node] = idx++;
    S.push(node);
    onStack.insert(node);

    for (int neighbor : graph[node]) {
        if (nodeIndex.find(neighbor) == nodeIndex.end()) {
            tarjanDFS(neighbor);
            lowlink[node] = min(lowlink[node], lowlink[neighbor]);
        } else if (onStack.find(neighbor) != onStack.end()) {
            lowlink[node] = min(lowlink[node], nodeIndex[neighbor]);
        }
    }

    if (lowlink[node] == nodeIndex[node]) {
        vector<int> scc;
        int w;
        do {
            w = S.top();
            S.pop();
            onStack.erase(w);
            scc.push_back(w);
        } while (w != node);
        sccs.push_back(scc);
    }
}

vector<vector<int>> tarjan(vector<pair<int, int>>& edges) {
    // Clear global structures for fresh computation
    graph.clear();
    nodeIndex.clear(); // Updated to use the new name
    lowlink.clear();
    while (!S.empty()) S.pop();
    onStack.clear();
    sccs.clear();
    idx = 0;

    // Build the graph
    for (const auto& edge : edges) {
        graph[edge.first].push_back(edge.second);
    }

    // Perform Tarjan's algorithm
    for (const auto& node : graph) {
        if (nodeIndex.find(node.first) == nodeIndex.end()) {
            tarjanDFS(node.first);
        }
    }

    return sccs;
}

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> edges;
        vector<int> ans(n + 1); // Changed to vector for dynamic size

        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            edges.pb({i, x});
            ans[i] = x;
        }

        string s;
        cin >> s;

        vector<vector<int>> result = tarjan(edges);
        int sz = result.size();
        vector<int> res(sz, 0);

        for (int i = 0; i < sz; ++i) {
            int cnt = 0;
            for (int x : result[i]) {
                if (s[x - 1] == '0') cnt++;
            }
            res[i] = cnt;
        }

        vector<pair<int, int>> prem;
        for (int i = 0; i < sz; ++i) {
            for (int x : result[i]) {
                prem.pb({ans[x], res[i]}); // Use ans[x]
            }
        }

        sort(prem.begin(), prem.end());

        for (const auto& x : prem) {
            cout << x.second << " "; // Added space for proper output
        }
        cout << endl;
    }

    return 0;
}
