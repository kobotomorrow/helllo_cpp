#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;

  set<int> s;

  for (long long i = 2; i * i <= N; i++) {
    while (N % i == 0) {
      cout << i << " ";
      N /= i;
    }
  }
  if (N >= 2) {
    cout << N;
  }
  cout << endl;
}