#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, p, q;
  cin >> n >> p >> q;

  vector<long long> d(n);
  for (auto &dd : d) {
    cin >> dd;
  }

  sort(d.begin(), d.end());

  if (p < q + d[0]) {
    cout << p << endl;
  } else {
    cout << q + d[0] << endl;
  }
}
