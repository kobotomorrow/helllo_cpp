#include <bits/stdc++.h>
using namespace std;

int rec(string &s, long long &count, int i, int j) {
  if (i == j) {
    if (s[i] != '0') {
      count++;
    }
    return s[i] - '0';
  }

  int cur = !(rec(s, count, i, j - 1) & int(s[j] - '0'));
  count += cur;
  return cur;
}

int main() {
  int n;
  string s;
  cin >> n >> s;

  long long count = 0;
  for (int i = 0; i < n; i++) {
    rec(s, count, i, n - 1);
  }

  cout << count << endl;
}
