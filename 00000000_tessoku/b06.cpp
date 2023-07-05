#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (auto &a : A) cin >> a;

  vector<int> sum(N + 1);
  sum[0] = 0;
  for(int i = 1; i <= N; i++) {
    sum[i] = sum[i - 1] + A[i - 1];
  }

  int Q;
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    int l, r;
    cin >> l >> r;

    int atr = sum[r] - sum[l - 1];
    int hzr = r - l + 1 - atr;

    if (atr == hzr) {
      cout << "draw" << endl;
    } else if (atr > hzr) {
      cout << "win" << endl;
    } else {
      cout << "lose" << endl;
    }
  }
}