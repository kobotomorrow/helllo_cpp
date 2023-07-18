#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    int l = i + 1;
    int r = n - 1;
    int m = 0;

    while (l < r) {
      m = (l + r) / 2;
      if (a.at(m) - a.at(i) <= k) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    if (a.at(l) - a.at(i) <= k) {
      ans += l - i;
    } else {
      ans += l - i - 1;
    }
  }

  cout << ans << endl;
}
