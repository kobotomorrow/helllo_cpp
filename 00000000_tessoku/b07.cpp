#include <bits/stdc++.h>
using namespace std;

int main() {
  int T, N;
  cin >> T >> N;

  vector<int> transition(T);

  for (int i = 0; i < N; i++) {
    int l, r;
    cin >> l >> r;

    transition[l]++;
    transition[r]--;
  }

  long long ans = 0;
  for (int i = 0; i < T; i++) {
    ans += transition[i];
    cout << ans << endl;
  }
}