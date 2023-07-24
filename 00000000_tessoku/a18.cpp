#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, s;
  cin >> n >> s;

  vector<int> a(n);
  for (auto &aa : a) cin >> aa;

  vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
  dp[0][0] = true;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= s; j++) {
      if (j - a[i - 1] >= 0 && dp[i - 1][j - a[i - 1]]) {
        dp[i][j] = true;
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  if (dp[n][s]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
