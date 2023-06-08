#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> S;
vector<int> P;

void rec(int current, vector<bool> &pettern, int &result) {
  // ベースケース
  if (current == pettern.size()) {
    vector<int> count(M, 0);
    for (int i = 0; i < pettern.size(); i ++) {
      if (pettern[i]) {
        int s = i + 1;
        for (int j = 0; j < M; j++) {
          for (int k = 0; k < S[j].size(); k++) {
            if (s == S[j][k]) {
              count[j]++;
            }
          }
        }
      }
    }
    bool all_ok = true;
    for (int i = 0; i < M; i++) {
      if (count[i] % 2 != P[i]) {
        all_ok = false;
        break;
      }
    }
    if (all_ok) {
      result++;
    }
    return;
  }

  // 再帰ステップ
  pettern[current] = true;
  rec(current + 1, pettern, result);

  pettern[current] = false;
  rec(current + 1, pettern, result);
}

int main() {
  cin >> N >> M;
  S.resize(M);
  P.resize(M);

  for (int i = 0; i < M; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int s;
      cin >> s;
      S[i].push_back(s);
    }
  }

  for (int i = 0; i < M; i++) {
    cin >> P[i];
  }

  vector<bool> pettern(N, true);
  int result = 0;
  rec(0, pettern, result);

  cout << result << endl;
}
