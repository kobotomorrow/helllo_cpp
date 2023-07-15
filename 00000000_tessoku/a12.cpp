#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

bool is_lowwer(int x) {
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += x / a[i];
  }
  if (sum >= k) {
    return true;
  }
  return false;
}

int main() {
  cin >> n >> k;

  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int l = 1;
  int r = 1'000'000'000;
  while (l < r) {
    int m = (l + r) / 2;
    bool ans = is_lowwer(m);
    if (ans) {
      r = m;
    } else {
      l = m + 1;
    }
  }

  cout << l << endl;
}
