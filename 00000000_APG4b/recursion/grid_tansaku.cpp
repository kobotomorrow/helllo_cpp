// マス目の探索
#include <bits/stdc++.h>
using namespace std;

bool is_valid_move(vector<vector<char>> &board, vector<vector<bool>> &checked, int x, int y) {
  int H = board.size();
  int W = board.at(0).size();

  // マスの外
  if (x < 0 || x >= H || y < 0 || y >= W) {
    return false;
  }


  // 壁
  if (board.at(x).at(y) == '#') {
    return false;
  }

  // チェック済み
  if (checked.at(x).at(y)) {
    return false;
  }

  return true;
}


bool reachable(vector<vector<char>> &board, vector<vector<bool>> &checked, int x, int y) {
  // ベース処理
  if (board.at(x).at(y) == 'g') {
    return true;
  }

  // 再起ステップ
  checked.at(x).at(y) = true;

  bool result = false;
  // 右
  if (is_valid_move(board, checked, x + 1, y) && reachable(board, checked, x + 1, y)) {
    result = true;
  }
  // 左
  if (is_valid_move(board, checked, x - 1, y) && reachable(board, checked, x - 1, y)) {
    result = true;
  }
  // 下
  if (is_valid_move(board, checked, x, y + 1) && reachable(board, checked, x, y + 1)) {
    result = true;
  }
  // 上
  if (is_valid_move(board, checked, x, y - 1) && reachable(board, checked, x, y - 1)) {
    result = true;
  }
  return result;
}

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<char>> board(H, vector<char>(W));
  int start_x = 0;
  int start_y = 0;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char c;
      cin >> c;
      board.at(i).at(j) = c;

      if (c == 's') {
        start_x = i;
        start_y = j;
      }
    }
  }

  vector<vector<bool>> checked(H, vector<bool>(W, false));

  if (reachable(board, checked, start_x, start_y)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
