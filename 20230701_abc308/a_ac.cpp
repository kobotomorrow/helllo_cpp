#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> A(8);
  for (int i = 0; i < 8; i++) {
    cin >> A[i];
  }

  bool is_ok = true;

  int pre = 0;
  for (auto a : A) {
    if (pre > a) {
      is_ok = false;
      break;
    }
    pre = a;
  }

  for (auto a : A) {
    if (a < 100 || 675 < a) {
      is_ok = false;
      break;
    }
  }

  for (auto a : A) {
    if (a % 25 != 0) {
      is_ok = false;
      break;
    }
  }

  if (is_ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}