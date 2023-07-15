#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  set<string> s;
  set<string> s2;

  for (int i = 0; i < n; i++) {
    string ss1;
    cin >> ss1;

    string ss2 = ss1;
    reverse(ss2.begin(), ss2.end());

    if (ss1 == ss2) {
      s2.insert(ss1);
      continue;
    }

    s.insert(ss1);
    s.insert(ss2);
  }

  cout << s2.size() + s.size() / 2 << endl;
}
