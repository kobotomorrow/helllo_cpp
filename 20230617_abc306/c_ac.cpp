#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> v(N * 3);

  for (int i = 0; i < N * 3; i++) {
    v[i].first = i;
    cin >> v[i].second;
  }

  map<int, vector<pair<int, int>>> m;
  for (int i = 0; i < N * 3; i++) {
    m[v[i].second].push_back(v[i]);
  }

  vector<pair<int, int>> ans;
  for (auto mm : m) {
    ans.push_back(mm.second[1]);
  }

  sort(ans.begin(), ans.end());

  for (auto a : ans) {
    cout << a.second << " ";
  }
  cout << endl;
}
