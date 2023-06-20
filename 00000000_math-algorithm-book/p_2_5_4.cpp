#include <bits/stdc++.h>
using namespace std;

void so(int n, set<int> &s) {
  bool is_so = true;
  for (int i = 2; i <= n; i++) {
    if (i == n) continue;
    if (n % i == 0) {
      is_so = false;
      break;
    }
  }
  if (is_so) {
    s.insert(n);
  }
}

int main() {
  int N;
  cin >> N;

  set<int> s;

  for (int i = 2; i <= N; i++) {
    so(i, s);
  }

  for (auto ss : s) {
    cout << ss << " ";
  }
  cout << endl;
}