#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> result;

  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      result.push_back(a.at(i));
      continue;
    }

    int pre = a.at(i - 1);
    int cur = a.at(i);
    int diff = cur - pre;

    if (diff == 0) {
      result.push_back(cur);
    } else if (diff > 0) {
      for (int j = 1; j <= diff; j++) {
        result.push_back(pre + j);
      }
    } else {
      for (int j = 1; j <= abs(diff); j++) {
        result.push_back(pre - j);
      }
    }
  }

  for (int i = 0; i < result.size(); i++) {
    cout << result.at(i);

    if (i != result.size() - 1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}