#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  map<int, int> num;

  for (int i = 0; i < N; i++) {
    int K;
    cin >> K;

    for (int j = 0; j < K; j++) {
      int A;
      cin >> A;
      num[A]++;
    }
  }

  int ans = 0;
  for (auto n : num) {
    if (n.second == N) {
      ans++;
    }
  }

  cout << ans << endl;
}
