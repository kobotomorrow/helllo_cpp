#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  string ans;
  for (int i = 0; i < N; i++) {
    if (i == 0 || S[i] != S[i - 1]) ans += S[i];
  }

  cout << ans.size() << endl;
}
