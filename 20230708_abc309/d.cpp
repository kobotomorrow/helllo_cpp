#include <bits/stdc++.h>
using namespace std;

int bfs(map<int, vector<int>> g, int start, vector<int> d) {
  queue<int> q;

  q.push(start);
  d[start] = 0;

  while(!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto v : g[u]) {
      if (d[v] == -1) {
        q.push(v);
        d[v] = d[u] + 1;
      }
    }
  }

  int max = 0;
  for (auto dd : d) {
    if (dd > max) {
      max = dd;
    }
  }
  return max;
}

int main() {
  int n1, n2, m;
  cin >> n1 >> n2 >> m;

  map<int, vector<int>> g1;
  map<int, vector<int>> g2;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    if (a <= n1) {
      g1[a].push_back(b);
      g1[b].push_back(a);
    } else {
      g2[a].push_back(b);
      g2[b].push_back(a);
    }
  }

  vector<int> d(n1 + n2 + 1, -1);
  int d1 = bfs(g1, 1, d);
  int d2 = bfs(g2, n1 + n2, d);

  cout << d1 + d2 + 1 << endl;
}