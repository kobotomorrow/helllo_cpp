#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  map<int, vector<int>> mp;
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    mp[a].push_back(b);
  }

  set<pair<int, int>> ans;
  for (int i = 1; i <= N; i++) {
    queue<int> que;
    que.push(i);

    while (!que.empty()) {
      int q = que.front();
      que.pop();

      for (auto m : mp[q]) {
        pair<int, int> p = make_pair(i, m);
        if (i != m && ans.count(p) == 0) {
          ans.insert(p);
          que.push(m);
        }
      }
    }
  }

  cout << ans.size() + N << endl;
}
