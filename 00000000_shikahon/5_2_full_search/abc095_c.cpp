#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  // 同じ枚数分のピザの比較
  int l = min(X, Y);
  int ans = (l * A + l * B) < (l * 2 * C) ? l * A + l * B : l * 2 * C;

  // 同じ枚数の場合は終了
  int m = max(X, Y) - l;
  if (m == 0) {
    cout << ans << endl;
    return 0;
  }

  // はみ出た枚数分のピザの比較
  int mod_ab = C * 2 * m;
  int mod_a_or_b = X > Y ? A * m : B * m;
  if (mod_ab < mod_a_or_b) {
    ans += mod_ab;
  } else {
    ans += mod_a_or_b;
  }

  cout << ans << endl;
}
