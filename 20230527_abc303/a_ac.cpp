#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string S, T;

  cin >> n >> S >> T;

  bool is_sim = true;

  for (int i = 0; i < n; i++) {
    if (S[i] == 'l' && T[i] == '1' || S[i] == '1' && T[i] == 'l') continue;
    if (S[i] == 'o' && T[i] == '0' || S[i] == '0' && T[i] == 'o') continue;
    if (S[i] == T[i]) continue;
    is_sim = false;
    break;
  }

  if (is_sim) cout << "Yes" << endl;
  else cout << "No" << endl;
}
