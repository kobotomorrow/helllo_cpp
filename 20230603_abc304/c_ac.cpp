#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;

  // 入力値の座標を保持
  vector<pair<int, int>> XY(N);
  for (int i = 0; i < N; i++) {
    cin >> XY[i].first >> XY[i].second;
  }

  // 感染リスト
  map<int, set<int>> K;
  for (int i = 0; i < N; i++) {
    K[i] = set<int>();
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;

      int x1 = XY[i].first;
      int y1 = XY[i].second;
      int x2 = XY[j].first;
      int y2 = XY[j].second;

      int dx = (x1 - x2) * (x1 - x2);
      int dy = (y1 - y2) * (y1 - y2);
      double d = sqrt(abs(dx) + abs(dy));

      if (d <= D) {
        K[i].insert(j);
      }
    }
  }

  set<int> ans = {0};
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int i = q.front();
    q.pop();

    for (auto k : K[i]) {
      if (ans.count(k) == 0) {
        ans.insert(k);
        q.push(k);
      }
    }
  }

  for (int i = 0; i < N; i++) {
    if (ans.count(i) == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
}
