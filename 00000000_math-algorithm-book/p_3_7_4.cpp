#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, S;
  cin >> N >> S;

  vector<int> A(N);
  for (auto &a : A) cin >> a;

  vector<vector<bool>> dp(N, vector<bool>(S + 1, false));
  dp[0][0] = true;
  if (A[0] <= S) dp[0][A[0]] = true;

  for (int i = 1; i < N; i++) {
    for (int j = 0; j < S; j++) {
      if (dp[i - 1][j]) {
        dp[i][j] = true;
        if (j + A[i] <= S) dp[i][j + A[i]] = true;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    if (dp[i][S]) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
}