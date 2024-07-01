//CSES : 1668 
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> in;

void dumb(int n) {
    vector<int> ans;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for (int v : adj[u]) {
            in[v]--;
            if (in[v] == 0) q.push(v);
        }
    }
    if (ans.size() != n) {
        cout << "IMPOSSIBLE";
    } else {
        for (auto it : ans) cout << it << ' ';
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    in.resize(n + 1, 0);
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }
    dumb(n);
    return 0;
}
