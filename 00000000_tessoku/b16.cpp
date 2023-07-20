#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<long long> dp;

long long rec(int nn) {
  if (dp[nn] != -1) {
    return dp[nn];
  }

  return dp[nn] = min(
    rec(nn - 1) + abs(a[nn] - a[nn - 1]),
    rec(nn - 2) + abs(a[nn] - a[nn - 2])
  );
}

int main() {
  int n;
  cin >> n;

  a.resize(n);
  for (auto &aa : a) cin >> aa;

  dp.resize(n, -1);
  dp[0] = 0;
  dp[1] = abs(a[1] - a[0]);

  cout << rec(n - 1) << endl;
}
