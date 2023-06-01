#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> H(N);
  for (auto &h : H) cin >> h;

  int move = 0;
  bool is_first_move = true;
  for (int i = 0; i < N;) {
    int count = 0;
    int num = H[i];
    i++;

    while (H[i - 1] >= H[i] && i < N) {
      count++;
      i++;
    }
    
    move = max(move, count);
  }

  cout << move << endl;
}
