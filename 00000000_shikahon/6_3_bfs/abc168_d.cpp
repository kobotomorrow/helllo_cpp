#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  map<int, vector<int>> mp;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    mp[a].push_back(b);
    mp[b].push_back(a);
  }

  vector<int> ans(N - 1);
  set<int> searched = {1};
  queue<int> que;
  que.push(1);
  int pre = 1;
  
  while(!que.empty()) {
    int now = que.front();
    que.pop();
    for (auto m : mp[now]) {
      if (searched.count(m)) continue;
      ans[m - 2] = now;
      que.push(m);
      searched.insert(m);
    }
    pre = now;
  }

  for (auto a : ans) {
    if (a == 0) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  for (auto a : ans) {
    cout << a << endl;
  }
}
