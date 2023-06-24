#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<string> S(N);
  for (auto &s : S) cin >> s;

  bool is_ok = false;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      string rs = S[i] + S[j];
      reverse(rs.begin(), rs.end());
      if (rs == (S[i] + S[j])) {
        is_ok = true;
        break;
      }
      if (is_ok) break;
    }
  }

  if (is_ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}