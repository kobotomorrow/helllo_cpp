#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<int>> x_total(H, vector<int>(W, 0));
  for (int i = 0; i < H; i++) {
    int row = 0;
    for (int j = 0; j < W; j++) {
      int x;
      cin >> x;

      row += x;
      x_total[i][j] = row;
    }
  }

  int Q;
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    int ans = 0;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for (int j = a - 1; j < c; j++) {
      ans += x_total[j][d - 1] - x_total[j][b - 2];
    }

    cout << ans << endl;
  }
}