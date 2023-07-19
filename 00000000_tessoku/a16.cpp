#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> b;
vector<int> dp;

int rec(int nn) {
  if (dp[nn] != -1) {
    return dp[nn];
  }

  int one = rec(nn - 1) + a[nn - 1];
  int two = rec(nn - 2) + b[nn - 2];
  return dp[nn] = min(one, two);
}

int main() {
  int n;
  cin >> n;

  a.resize(n - 1);
  for (auto &aa : a) cin >> aa;
  b.resize(n - 2);
  for (auto &bb : b) cin >> bb;

  dp.resize(n, -1);
  dp[0] = 0;
  dp[1] = a[0];
  cout << rec(n - 1) << endl;
}
