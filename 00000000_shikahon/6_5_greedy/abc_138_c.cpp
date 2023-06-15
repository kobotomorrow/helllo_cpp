#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> V(N);
  for (auto &v : V) cin >> v;

  sort(V.begin(), V.end());

  float ans = V[0];
  for (int i = 1; i < N; i++) {
    ans = (ans + V[i]) / 2.0;
  }

  cout << ans << endl;
}
