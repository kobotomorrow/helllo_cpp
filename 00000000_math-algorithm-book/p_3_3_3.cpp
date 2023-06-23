#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, r;
  cin >> n >> r;

  // nCr = n! / (n-r)! * r!
  ll ans = 1;
  for (int i = n; i > n - r; i--) {
    ans *= i;
  }

  for (int i = r; i > 0; i--) {
    ans /= i;
  }

  cout << ans << endl;
}