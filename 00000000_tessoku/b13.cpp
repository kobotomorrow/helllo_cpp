#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<long long> a(n + 1);
  a[0] = 0;

  for (int i = 1; i <= n; i++) {
    if (i == 0) cin >> a[i];
    else {
      int aa;
      cin >> aa;
      a[i] = a[i - 1] + aa;
    }
  }

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = i;
    int r = n;
    int m = 0;

    while (l < r) {
      m = (l + r) / 2;

      if (a[m] - a[i - 1] <= k) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    if (a[l] - a[i - 1] <= k) {
      ans += l - (i - 1);
    } else {
      ans += l - 1 - (i - 1);
    }

  }

  cout << ans << endl;
}
