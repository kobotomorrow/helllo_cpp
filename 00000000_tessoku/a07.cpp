#include <bits/stdc++.h>
using namespace std;

int main() {
  int D, N;
  cin >> D >> N;

  vector<int> ratio(D + 1, 0);

  for (int i = 0; i < N; i++) {
    int l, r;
    cin >> l >> r;

    ratio[l]++;
    ratio[r + 1]--;
  }

  int ans = 0;
  for (int i = 1; i <= D; i++) {
    ans += ratio[i];
    cout << ans << endl;
  }
}