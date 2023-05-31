#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  // mapを使って集計する
  map<int, int> B;
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    B[A]++;
  }

  // mapをソートするため、pairに詰め替える
  vector<pair<int, int>> P;
  for (auto b : B) {
    P.push_back(make_pair(b.second, b.first));
  }
  sort(P.begin(), P.end());

  int t = P.size() - K;
  int ans = 0;

  for (int i = 0; i < t; i++) {
    ans += P[i].first;
  }

  cout << ans << endl;
}
