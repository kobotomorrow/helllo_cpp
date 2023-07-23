#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void bfs_l(vector<string> &s, vector<vector<bool>> &visited, int y, int x);
void bfs_t(vector<string> &s, vector<vector<bool>> &visited, int y, int x);
void bfs_b(vector<string> &s, vector<vector<bool>> &visited, int y, int x);
void bfs_r(vector<string> &s, vector<vector<bool>> &visited, int y, int x);

void bfs_r(vector<string> &s, vector<vector<bool>> &visited, int y, int x) {
  if (visited[y][x]) {
    if (s[y][x + 1] == '.') {
      bfs_r(s, visited, y, x + 1);
    }
    return;
  }

  if (s[y][x] == '#') {
    if (s[y - 1][x - 1] == '.') {
      bfs_t(s, visited, y - 1, x - 1);
    }
    if (s[y + 1][x - 1] == '.') {
      bfs_b(s, visited, y + 1, x - 1);
    }
    return;
  }

  ans++;
  
  visited[y][x] = true;

  bfs_r(s, visited, y, x + 1);
}

void bfs_l(vector<string> &s, vector<vector<bool>> &visited, int y, int x) {
  if (visited[y][x]) {
    if (s[y][x - 1] == '.') {
      bfs_l(s, visited, y, x - 1);
    }
    return;
  }

  if (s[y][x] == '#') {
    if (s[y - 1][x + 1] == '.') {
      bfs_t(s, visited, y - 1, x + 1);
    }
    if (s[y + 1][x + 1] == '.') {
      bfs_b(s, visited, y + 1, x + 1);
    }
    return;
  }

  ans++;
  
  visited[y][x] = true;

  bfs_l(s, visited, y, x - 1);
}

void bfs_t(vector<string> &s, vector<vector<bool>> &visited, int y, int x) {
  if (visited[y][x]) {
    if (s[y - 1][x] == '.') {
      bfs_t(s, visited, y - 1, x);
    }
    return;
  }

  if (s[y][x] == '#') {
    if (s[y + 1][x + 1]) {
      bfs_r(s, visited, y + 1, x + 1);
    }
    if (s[y + 1][x - 1]) {
      bfs_l(s, visited, y + 1, x - 1);
    }
    return;
  }

  ans++;
  
  visited[y][x] = true;

  bfs_t(s, visited, y - 1, x);
}

void bfs_b(vector<string> &s, vector<vector<bool>> &visited, int y, int x) {
  if (visited[y][x]) {
    if (s[y + 1][x] == '.') {
      bfs_b(s, visited, y + 1, x);
    }
    return;
  }

  if (s[y][x] == '#') {
    if (s[y - 1][x + 1] == '.') {
      bfs_r(s, visited, y - 1, x + 1);
    }
    if (s[y - 1][x - 1] == '.') {
      bfs_l(s, visited, y - 1, x - 1);
    }
    return;
  }

  ans++;
  
  visited[y][x] = true;

  bfs_b(s, visited, y + 1, x);
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  vector<vector<bool>> visited(n, vector<bool>(m, false));

  bfs_r(s, visited, 1, 1);
  bfs_b(s, visited, 1, 1);

  cout << ans << endl;
}
