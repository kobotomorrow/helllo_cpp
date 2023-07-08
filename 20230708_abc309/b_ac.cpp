#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<string> A(N);
  for (auto &a : A) cin >> a;

  for (int i = 0; i < N; i++) {
    if (i == 0) {
      A[i] = A[i + 1][0] + A[i];
    } else if (i == N - 1) {
      A[i] = A[i] + A[i - 1][N];
    } else {
      A[i] = A[i + 1][0] + A[i] + A[i - 1][N];
    }
  }

  for (int i = 0; i < N; i++) {
    if (i == 0) {
      A[i].erase(N, 1);
      continue;
    }
    if (i == N - 1) {
      A[i].erase(0, 1);
      continue;
    }
    A[i].erase(1, 1);
    A[i].erase(N - 1, 1);
  }

  for (auto a : A) cout << a << endl;
}