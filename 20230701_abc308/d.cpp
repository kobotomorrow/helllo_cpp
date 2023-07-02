#include <bits/stdc++.h>
using namespace std;

int H, W;
map<char, char> snk;
vector<string> S;
vector<vector<bool>> visited;

void rec(int h, int w, char prev) {
  if (h < 0 || h >= H || w < 0 || w >= W) {
    return;
  }
  if (S[h][w] != snk[prev]) {
    return;
  }
  if (visited[h][w]) {
    return;
  }

  visited[h][w] = true;
  prev = S[h][w];

  rec(h + 1, w, prev);
  rec(h - 1, w, prev);
  rec(h, w + 1, prev);
  rec(h, w - 1, prev);
}

int main() {
  snk['s'] = 'n';
  snk['n'] = 'u';
  snk['u'] = 'k';
  snk['k'] = 'e';
  snk['e'] = 's';

  cin >> H >> W;

  S.resize(H);
  for (int i = 0; i < H; i++) {
    cin >> S[i];
  }

  if (S[0][0] != 's') {
    cout << "No" << endl;
    return 0;
  }

  visited.resize(H, vector<bool>(W, false));

  rec(0, 0, 'e');

  if (visited[H - 1][W - 1]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
