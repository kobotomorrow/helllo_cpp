#include <bits/stdc++.h>
using namespace std;

int main() {
  int row;
  int col;
  cin >> row >> col;

  vector<string> board(row);

  for (int i = 0; i < row; i++) {
    cin >> board.at(i);
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (board.at(i).at(j) == '#') {
        // Top
        if (i != 0) {
          if (board.at(i - 1).at(j) == '.') {
            board.at(i - 1).at(j) = '1';
          }
          else if (board.at(i - 1).at(j) != '#') {
            char current = board.at(i - 1).at(j);
            int current_int = current - '0';
            current_int += 1;
            board.at(i - 1).at(j) = to_string(current_int)[0];
          }
        }
        if (j != board.at(i).size() - 1) {
          // Right
          if (board.at(i).at(j + 1) == '.') {
            board.at(i).at(j + 1) = '1';
          }
          else if (board.at(i).at(j + 1) != '#') {
            char current = board.at(i).at(j + 1);
            int current_int = current - '0';
            current_int += 1;
            board.at(i).at(j + 1) = to_string(current_int)[0];
          }
        }
        // Bottom
        if (i != board.size() - 1) {
          if (board.at(i + 1).at(j) == '.') {
            board.at(i + 1).at(j) = '1';
          }
          else if (board.at(i + 1).at(j) != '#') {
            char current = board.at(i + 1).at(j);
            int current_int = current - '0';
            current_int += 1;
            board.at(i + 1).at(j) = to_string(current_int)[0];
          }
        }
        // Left
        if (j != 0) {
          if (board.at(i).at(j - 1) == '.') {
            board.at(i).at(j - 1) = '1';
          }
          else if (board.at(i).at(j - 1) != '#') {
            char current = board.at(i).at(j - 1);
            int current_int = current - '0';
            current_int += 1;
            board.at(i).at(j - 1) = to_string(current_int)[0];
          }
        }
        // Top Right
        if (i != 0 && j != board.at(i).size() - 1) {
          if (board.at(i - 1).at(j + 1) == '.') {
            board.at(i - 1).at(j + 1) = '1';
          }
          else if (board.at(i - 1).at(j + 1) != '#') {
            char current = board.at(i - 1).at(j + 1);
            int current_int = current - '0';
            current_int += 1;
            board.at(i - 1).at(j + 1) = to_string(current_int)[0];
          }
        }
        // Bottom Right
        if (i != board.size() - 1 && j != board.at(i).size() - 1) {
          if (board.at(i + 1).at(j + 1) == '.') {
            board.at(i + 1).at(j + 1) = '1';
          }
          else if (board.at(i + 1).at(j + 1) != '#') {
            char current = board.at(i + 1).at(j + 1);
            int current_int = current - '0';
            current_int += 1;
            board.at(i + 1).at(j + 1) = to_string(current_int)[0];
          }
        }
        // Bottom Left
        if (i != board.size() - 1 && j != 0) {
          if (board.at(i + 1).at(j - 1) == '.') {
            board.at(i + 1).at(j - 1) = '1';
          }
          else if (board.at(i + 1).at(j - 1) != '#') {
            char current = board.at(i + 1).at(j - 1);
            int current_int = current - '0';
            current_int += 1;
            board.at(i + 1).at(j - 1) = to_string(current_int)[0];
          }
        }
        // Top Left
        if (i != 0 && j != 0) {
          if (board.at(i - 1).at(j - 1) == '.') {
            board.at(i - 1).at(j - 1) = '1';
          }
          else if (board.at(i - 1).at(j - 1) != '#') {
            char current = board.at(i - 1).at(j - 1);
            int current_int = current - '0';
            current_int += 1;
            board.at(i - 1).at(j - 1) = to_string(current_int)[0];
          }
        }
      }
    }
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < board.at(i).size(); j++) {
      if (board.at(i).at(j) == '.') {
        board.at(i).at(j) = '0';
      }
    }
  }

  for (int i = 0; i < row; i++) {
    cout << board.at(i) << endl;
  }
}
