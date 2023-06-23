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

  set<long long> searched;
  long long ans = 0;
  for (auto a : A) {
    if (a.second < 1) continue;
    if (searched.count(a.first)) continue;
    if (a.first == 50000) {
      ans += comb(a.second, 2);
      searched.insert(a.first);
    } else if (A[100000 - a.first] > 0) {
      ans += a.second * A[100000 - a.first];
      searched.insert(a.first);
      searched.insert(100000 - a.first);
    }
  }

  cout << ans << endl;
}