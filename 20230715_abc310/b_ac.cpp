#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> p(n);
  vector<set<int>> f(n);

  for (int i = 0; i < n; i++) {
    cin >> p[i];

    int c;
    cin >> c;
    for (int j = 0; j < c; j++) {
      int x;
      cin >> x;
      f[i].insert(x);
    }
  }


  bool ok = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (p[j] > p[i]) continue;

      bool out1 = false;
      for (auto ff : f[i]) {
        if (f[j].count(ff) == 0) {
          out1 = true;
          break;
        }
      }
      if (out1) continue;

      if (p[j] < p[i]) {
        ok = true;
        break;
      }

      for (auto ff : f[j]) {
        if (f[i].count(ff) == 0) {
          ok = true;
          break;
        }
        if (ok) break;
      }
    }
    if (ok) break;
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
