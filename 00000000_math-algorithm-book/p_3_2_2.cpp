#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<long long> A(N);
  for (auto &a : A) cin >> a;

  long long a = A[0];
  for (int i = 1; i < N; i++) {
    long long b = A[i];
    while (a > 0 && b > 0) {
      if (a > b) a = a % b;
      else b = b % a;
    }
    a = max(a, b);
  }

  cout << a << endl;
}