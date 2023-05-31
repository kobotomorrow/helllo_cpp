#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  set<int> S;

  for (int i = 0; i < N; i++) {
    int n;
    cin >> n;
    A.at(i) = n;
    S.insert(n);
  }

  if (A.size() == S.size()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
