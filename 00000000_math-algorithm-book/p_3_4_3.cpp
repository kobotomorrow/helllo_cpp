#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (auto &a : A) cin >> a;
  vector<int> B(N);
  for (auto &b : B) cin >> b;

  double ans = 0;

  for (int i = 0; i < N; i++) {
    ans += A[i] / 3.0 + B[i] * 2.0 / 3.0;
  }

  cout << ans << endl;
}