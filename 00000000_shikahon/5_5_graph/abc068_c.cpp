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
    mp[b].push_back(a);
  }

  string ans = "IMPOSSIBLE";
  vector<int> target = mp[1];
  bool is_end = false;
  for (auto t : target) {
    for (auto tt : mp[t]) {
      if (tt == N) {
        ans = "POSSIBLE";
        is_end = true;
        break;
      }
    }
    if (is_end) break;
  }

  cout << ans << endl;
}
