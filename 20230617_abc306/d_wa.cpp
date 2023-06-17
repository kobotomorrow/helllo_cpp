#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<pair<int, long long>> V(N);
  for(int i = 0; i < N; i++) {
    cin >> V[i].first >> V[i].second;
  }

  long long mx = 0;
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (V[i].first == 1) {
      mx = max(mx, V[i].second);
      if (i == (N - 1)) {
        ans += mx;
        mx = 0;
      }
    }
    if (V[i].first == 0) {
      if (V[i].second >= 0 || (mx + V[i].second) >= 0) {
        ans += V[i].second;
        ans += mx;
        mx = 0;
      }
    }
  }

  cout << ans << endl;
}
