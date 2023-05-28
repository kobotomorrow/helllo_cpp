#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> inputs;
  for (int i = 0; i < M; i++) {
    vector<int> row;
    for (int j = 0; j < N; j++) {
      int tmp;
      cin >> tmp;
      row.push_back(tmp);
    }
    inputs.push_back(row);
  }


  map<int, set<int>> pairs;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      
      if (j == 0) {
        pairs[inputs[i][j]].insert(inputs[i][j + 1]);
      } else if (j == N - 1) {
        pairs[inputs[i][j]].insert(inputs[i][j - 1]);
      } else {
        pairs[inputs[i][j]].insert(inputs[i][j - 1]);
        pairs[inputs[i][j]].insert(inputs[i][j + 1]);
      }
    }
  }

  set<vector<int>> ans;
  for (auto p : pairs) {
    for (int i = 1; i <= N; i++) {
      if (p.first == i) continue;
      if (p.second.find(i) == p.second.end()) {
        vector<int> tmp;
        tmp.push_back(p.first);
        tmp.push_back(i);
        sort(tmp.begin(), tmp.end());
        ans.insert(tmp);
      }
    }
  }

  cout << ans.size() << endl;
}
