#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;

  map<long long, long long> mp;
  for (long long i = 0; i < N; i++) {
    long long A;
    cin >> A;
    mp[A % 200]++;
  }

  long long ans = 0;

  for (auto m : mp) {
    ans += m.second * (m.second - 1) / 2;
  }

  cout << ans << endl;
}
