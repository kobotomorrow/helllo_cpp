#include <bits/stdc++.h>
using namespace std;

void decrease(vector<int> &H, int str, int end) {
  for (int i = str; i <= end; i++) {
    H[i]--;
  }
}

int main() {
  int N;
  cin >> N;

  vector<int> H(N);
  for (auto &h : H) cin >> h;

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int j = i;
    for (int k = H[i]; k > 0; k--) {
      while (j < N && H[j] != 0) {
        j++;
      }
      decrease(H, i, j - 1);
      ans++;
      j = i;
    }
  }

  cout << ans << endl;
}
