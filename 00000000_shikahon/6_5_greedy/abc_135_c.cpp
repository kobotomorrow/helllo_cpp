#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<long long> A(N + 1);
  for (auto &a : A) cin >> a;
  vector<long long> B(N);
  for (auto &b : B) cin >> b;

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (B[i] <= A[i]) {
      ans += B[i];
      A[i] = 0;
      continue;
    }
    if (B[i] > A[i]) {
      ans += A[i];
      B[i] -= A[i];
      A[i] = 0;
      if (B[i] > A[i + 1]) {
        ans += A[i + 1];
        B[i] -= A[i + 1];
        A[i + 1] = 0;
      } else {
        ans += B[i];
        A[i + 1] -= B[i];
      }
    }
  }
  cout << ans << endl;
}
