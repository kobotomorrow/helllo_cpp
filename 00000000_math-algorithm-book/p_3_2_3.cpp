#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main() {
  int N;
  cin >> N;

  vector<ull> A(N);
  for (auto &a : A) cin >> a;

  ull a = A[0];
  for (int i = 1; i < N; i++) {
    ull b = A[i];
    ull o_a = a;
    ull o_b = b;
    while (a > 0 && b > 0) {
      if (a > b) a = a % b;
      else b = b % a;
    }
    // AB == GL
    // AB / G = L
    // (桁溢れ対策)
    // B / G * A = L
    a = o_b / max(a, b) * o_a;
  }

  cout << a << endl;
}