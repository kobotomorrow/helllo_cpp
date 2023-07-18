#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  vector<int> as(n);
  as = a;
  sort(as.begin(), as.end());

  map<int, int> bs;
  int pre = 0;
  int idx = 1;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      bs[as.at(i)] = idx;
      pre = as.at(i);
      continue;
    }

    if (pre != as.at(i)) {
      idx++;
    }
    bs[as.at(i)] = idx;
    pre = as.at(i);
  }

  for (auto aa : a) {
    cout << bs[aa] << endl;
  }
}
