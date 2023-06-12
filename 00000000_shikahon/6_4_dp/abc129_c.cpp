#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<bool> is_broken;
vector<long long> dp;

long long rec(int i) {
  // ベースケース(メモ)
  if (dp[i] != -1) {
    return dp[i];
  }

  // 再帰ステップ
  long long left = 0;
  long long right = 0;
  if (!is_broken[i - 1]) { 
    left = rec(i - 1);
  }
  if (!is_broken[i - 2]) { 
    right = rec(i - 2);
  }
  dp[i] = (left + right) % 1000000007;

  return dp[i];
}

int main() {
  cin >> N >> M;

  is_broken.resize(N + 1, false);

  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    is_broken[a] = true;
  }

  dp.resize(N + 1, -1);
  dp[0] = 1;
  if(!is_broken[1]) dp[1] = 1;

  cout << rec(N) << endl;
}
