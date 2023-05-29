#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> m(M, vector<int>(2));

  for (auto &mm : m) {
    int s, c;
    cin >> s >> c;
    mm.at(0) = s;
    mm.at(1) = c;
  }

  int str = pow(10, N - 1);
  if (N == 1) str = 0;
  int end = pow(10, N);

  int ans = -1;
  for (int i = str; i < end; i++) {
    string s = to_string(i);

    bool is_match = true;
    for (auto mm : m) {
      if ((s.at(mm.at(0) - 1) != to_string(mm.at(1)).at(0))) {
        is_match = false;
        break;
      }
    }
    if (is_match) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;
}
