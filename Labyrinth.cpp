#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
#define ii pair<int, int>
 
bool vis[1069][1069];
int prev_dir[1069][1069]; // To store direction to reach each cell
 
int main() {
  int n, m;
  ii s, e;
  cin >> n >> m;
 
  char a[1069][1069];
  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, 1, 0, -1};
  string dir = "DRUL";
 
  // Input grid and find start ('A') and end ('B') positions
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (a[i][j] == 'A') {
        s = {i, j};
      }
      if (a[i][j] == 'B') {
        e = {i, j};
      }
    }
  }
 
  // BFS to find the shortest path from 'A' to 'B'
  queue<ii> q;
  q.push(s);
  vis[s.first][s.second] = true;
 
  while (!q.empty()) {
    ii u = q.front();
    q.pop();
 
    // Explore all 4 directions
    for (int i = 0; i < 4; ++i) {
      int nx = u.first + dx[i];
      int ny = u.second + dy[i];
 
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] &&
          a[nx][ny] != '#') {
        vis[nx][ny] = true;
        prev_dir[nx][ny] = i;
        q.push({nx, ny});
      }
    }
  }
 
  // Check if we can reach 'B' from 'A'
  if (vis[e.first][e.second]) {
    cout << "YES"
         << "\n";
 
    // Trace back the path using prev_dir
    vector<int> path;
    ii current = e;
 
    while (current != s) {
      int d = prev_dir[current.first][current.second];
      path.push_back(d);
      current.first -= dx[d];
      current.second -= dy[d];
    }
 
    reverse(path.begin(), path.end());
 
    cout << path.size() << "\n";
    for (int d : path) {
      cout << dir[d];
    }
    cout << "\n";
 
  } else {
    cout << "NO"
         << "\n";
  }
 
  return 0;
}
