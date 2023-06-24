#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  string pre = S;
  while (true) {
    string removed = "";
    string buf = "";
    bool is_kakko = false;
    for (int i = 0; i < pre.size(); i++) {
      if (pre[i] == '(') {
        is_kakko = true;
        if (buf != "") {
          removed += buf;
          buf = "";
        }
        buf += pre[i];
      } else if (pre[i] == ')') {
        if (buf != "") {
          buf = "";
          is_kakko = false;
        } else {
          removed += pre[i];
        }
      } else if (is_kakko) {
        buf += pre[i];
      } else {
        removed += pre[i];
      }
    }
    if (buf != "") {
      removed += buf;
    }
    if (pre == removed) {
      cout << removed << endl;
      break;
    }
    pre = removed;
  }
}