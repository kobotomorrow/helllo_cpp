#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  size_t n = s.size() - 1;

  int64_t ans = 0;

  for (int bit = 0; bit < (1 << n); bit++) {
    int64_t sum = 0;
    int64_t a = s[0] - '0';

    for (int i = 0; i < n; i++) {
      if (bit & (1 << i)) {
        sum += a;
        a = 0;
      }
      a = a * 10 + (s[i + 1] - '0');
    }
    sum += a;
    ans += sum;
  }

  cout << ans << endl;
}
