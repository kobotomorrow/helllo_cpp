#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  // 高さ
  map<int, int> H;
  for (int i = 1; i <= N; i++) {
    int h;
    cin >> h;
    H[i] = h;
  }

  // 道-接続している展望台の中で最も高い展望台の高さ
  map<int, int> R;
  for (int i = 1; i <= N; i++) R[i] = 0;
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    
    R[A] = max(R[A], H[B]);
    R[B] = max(R[B], H[A]);
  }

  int ans = 0;
  for (auto r : R) {
    if (H[r.first] > r.second) ans++;
  }

  cout << ans << endl;
}
