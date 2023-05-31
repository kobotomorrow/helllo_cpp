#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  map<int, int> A;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[a]++;
  }

  int ans = 0;
  for (auto a: A) {
    if (a.first == a.second) continue;
    if (a.first < a.second) ans += a.second - a.first;
    else ans += a.second;
  }

  cout << ans << endl;
}
