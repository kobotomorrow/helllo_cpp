#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  long long K;
  cin >> N >> K;

  vector<vector<long long>> AB(N, vector<long long>(2));
  for (long long i = 0; i < N; i++) {
    cin >> AB.at(i).at(0) >> AB.at(i).at(1);
  }

  sort(AB.begin(), AB.end());

  unsigned long long count = 0;
  for (auto ab : AB) {
    count += ab.at(1);
  }

  if (K >= count) {
    cout << 1 << endl;
    return 0;
  }

  unsigned long long ans = 1;
  for (long long i = 0; i < N; i++) {
    count -= AB.at(i).at(1);
    if (K >= count) {
      ans += AB.at(i).at(0);
      break;
    }
  }

  cout << ans << endl;
}