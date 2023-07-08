#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> Z(1501, vector<int>(1501, 0));
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    Z[y][x] += 1;
  }

  for (int i = 1; i < 1501; i++) {
    for (int j = 1; j < 1501; j++) {
      Z[i][j] += Z[i][j - 1];
    }
  }

  for (int i = 1; i < 1501; i++) {
    for (int j = 1; j < 1501; j++) {
      Z[i][j] += Z[i - 1][j];
    }
  }

  int Q;
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << Z[y2][x2] - Z[y1 - 1][x2] - Z[y2][x1 - 1] + Z[y1 - 1][x1 - 1] << endl;
  }
}