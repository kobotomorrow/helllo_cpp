#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<string> C(N);
  for (auto &c : C) cin >> c;

  vector<string> D(M);
  for (auto &d : D) cin >> d;

  vector<int> P(M + 1);
  for (auto &p : P) cin >> p;

  map<string, int> DP;
  int other_price = P[0];
  for (int i = 0; i < M; i++) {
    DP[D[i]] = P[i + 1];
  }

  int ans = 0;
  for (auto c : C) {
    if (DP[c] == 0) {
      ans += other_price;
    } else {
      ans += DP[c];
    }
  }

  cout << ans << endl;
}