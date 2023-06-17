#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v(64);
  for (int i = 0; i < 64; i++) {
    cin >> v[i];
  }
  reverse(v.begin(), v.end());

  string S;
  for (auto vv : v) {
    S += to_string(vv);
  }

  cout << bitset<64>(S).to_ullong() << endl;
}
