#include <bits/stdc++.h>
using namespace std;

int N, M, X;
bool first_result = true;

void rec(int current, vector<bool> &pettern, vector<int> &price, vector<vector<int>> &A, int &result) {
  // ベースケース
  if (current == N) {
    int amount = 0;
    vector<int> skill(M);
    for (int i = 0; i < N; i++) {
      if (pettern[i]) {
        amount += price[i];
        for (int j = 0; j < M; j++) {
          skill[j] += A[i][j];
        }
      }
    }
    bool all_ok = true;
    for (auto s : skill) {
      if (s < X) {
        all_ok = false;
        break;
      }
    }
    if (!all_ok) return;
    if (first_result) {
      result = amount;
      first_result = false;
      return;
    }
    result = min(result, amount);
    return;
  }

  // 再帰ステップ
  pettern[current] = true;
  rec(current + 1, pettern, price, A, result);

  pettern[current] = false;
  rec(current + 1, pettern, price, A, result);
}

int main() {
  cin >> N >> M >> X;

  vector<int> price(N);
  vector<vector<int>> A(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    cin >> price[i];
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }

  vector<bool> pettern(N);
  int result = -1;
  rec(0, pettern, price, A, result);

  cout << result << endl;
}
