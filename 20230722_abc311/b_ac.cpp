#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int d;
  cin >> n >> d;

  vector<string> s(n);
  for (auto &x : s) cin >> x;

  int ans = 0;
  int count = 0;

  for (int i = 0; i < d; i++) {
    bool all_free = true;
    for (int j = 0; j < n; j++) {
      if (s[j][i] == 'x') {
        all_free = false;
        break;
      }
    }
    if (all_free) {
      count++;
    } else {
      ans = max(ans, count);
      count = 0;
    }
  }
  ans = max(ans, count);

  cout << ans << endl;
}
