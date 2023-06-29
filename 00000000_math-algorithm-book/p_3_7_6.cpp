#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  vector<long long> dp(N + 1);
  dp[0] = 0;
  dp[1] = A[1];

  for (int i = 2; i < N + 1; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + A[i]);
  }

  cout << dp[N] << endl;
}