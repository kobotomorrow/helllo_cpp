#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  priority_queue<int> q;
  q.push(1);

  for (int i = 2; i <= x; i++) {
    int j = 2;
    int n = 0;
    while (true) {
      n = pow(i, j);
      if (n > x) break;
      q.push(n);
      j++;
    }
  }

  cout << q.top() << endl;
}
