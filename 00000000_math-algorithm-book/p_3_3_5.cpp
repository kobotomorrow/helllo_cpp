#include <bits/stdc++.h>
using namespace std;

long long comb(long long n, long long r) {
  long long t = 1;
  for (int i = n; i > n - r; i--) {
    t *= i;
  }
  for (int i = r; r > 1; r--) {
    t /= r;
  }
  return t;
}

int main() {
  int N;
  cin >> N;

  map<long long, long long> A;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[a]++;
  }

  long long ans = 0;
  ans += comb(A[1], 2);
  ans += comb(A[2], 2);
  ans += comb(A[3], 2);

  cout << ans << endl;
}