#include <bits/stdc++.h>
using namespace std;

int H, W, K;
vector<vector<char>> C;

void rec(int current, vector<bool> &pettern, int &result) {
  // ベースケース
  if (current == pettern.size()) {
    vector<vector<char>> CC = C;
    for (int i = 0; i < pettern.size(); i++) {
      if (pettern[i]) {
        if (i < H) {
          for (int j = 0; j < W; j++) {
            CC[i][j] = 'R';
          }
        } else {
          for (int j = 0; j < H; j++) {
            CC[j][i - H] = 'C';
          }
        }
      }
    }

    int count = 0;
    for (auto cc : CC) {
      for (auto c : cc) {
        if (c == '#') {
          count++;
        }
      }
    }
    if (count == K) {
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
  cin >> H >> W >> K;
  C.resize(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> C[i][j];
    }
  }

  vector<bool> pettern(H + W, false);
  int result = 0;
  rec(0, pettern, result);

  cout << result << endl;
}
