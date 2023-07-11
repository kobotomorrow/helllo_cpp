#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &aa : a) cin >> aa;
  sort(a.begin(), a.end());

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;

    cout << lower_bound(a.begin(), a.end(), x) - a.begin() << endl;
  }
}