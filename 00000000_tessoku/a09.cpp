#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  vector<vector<int>> Z(H + 1, vector<int>(W + 1, 0));

  for (int i = 0; i < N; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    Z[a - 1][b - 1] += 1;
    Z[a - 1][d] -= 1;
    Z[c][b - 1] -= 1;
    Z[c][d] += 1;
  }

  for (int i = 0; i < H + 1; i++) {
    for (int j = 1; j < W + 1; j++) {
      Z[i][j] += Z[i][j - 1];
    }
  }

  for (int i = 1; i < H + 1; i++) {
    for (int j = 0; j < W + 1; j++) {
      Z[i][j] += Z[i - 1][j];
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << Z[i][j] << " ";
    }
    cout << endl;
  }
}