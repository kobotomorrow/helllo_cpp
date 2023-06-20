#include <bits/stdc++.h>
using namespace std;

long long rec(int i) {
  if (i == 1) {
    return 1;
  }

  return rec(i - 1) * i;
}

int main() {
  int N;
  cin >> N;

  cout << rec(N) << endl;
}