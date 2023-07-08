#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<vector<int>> E(1501, vector<int>(1501, 0));

  for (int i = 0; i < N; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    E[b][a] += 1;
    E[b][c] -= 1;
    E[d][a] -= 1;
    E[d][c] += 1;
  }

  for (int i = 0; i < 1501; i++) {
    for (int j = 1; j < 1501; j++) {
      E[i][j] += E[i][j - 1];
    }
  }

  for (int i = 0; i < 1501; i++) {
    for (int j = 1; j < 1501; j++) {
      E[j][i] += E[j - 1][i];
    }
  }

  int ans = 0;
  for (int i = 0; i < 1501; i++) {
    for (int j = 0; j < 1501; j++) {
      if (E[i][j] > 0) ans++;
    }
  }

  cout << ans << endl;
}