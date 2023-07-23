#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  bool a = false;
  bool b = false;
  bool c = false;
  for (int i = 0; i < n; i++) {
    char ch = s[i];

    if (ch == 'A') a = true;
    else if (ch == 'B') b = true;
    else if (ch == 'C') c = true;

    if (a && b && c) {
      cout << i + 1 << endl;
      return 0;
    }
  }
}
