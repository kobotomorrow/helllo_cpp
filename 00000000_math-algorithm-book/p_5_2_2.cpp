#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;

  double s =  log2(N + 1);
  if (floor(s) == s) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }
}