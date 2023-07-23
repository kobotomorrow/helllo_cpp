#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &a : A) {
    cin >> a;
  }

  vector<int> T(N);
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      T[i] = A[i];
      continue;
    }
    if (T[i - 1] < A[i]) {
      T[i] = A[i];
    } else {
      T[i] = T[i - 1];
    }
  }

  vector<int> TR(N);
  for (int i = N - 1; i >= 0; i--) {
    if (i == N - 1) {
      TR[i] = A[i];
      continue;
    }
    if (TR[i + 1] < A[i]) {
      TR[i] = A[i];
    } else {
      TR[i] = TR[i + 1];
    }
  }

  int D;
  cin >> D;
  for (int i = 0; i < D; i++) {
    int l, r;
    cin >> l >> r;
    l -= 2;

    int ml = 0;
    if (l >= 0) ml = T[l];

    int mr = 0;
    if (r < N) mr = TR[r];

    cout << max(ml, mr) << endl;
  }
}