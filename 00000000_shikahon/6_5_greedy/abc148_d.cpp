#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (auto &a : A) cin >> a;

  int find = 1;
  int ans = 0;

  for (auto a : A) {
    if (a == find) {
      find++;
    } else {
      ans++;
    }
  }

  if (find == 1) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}
