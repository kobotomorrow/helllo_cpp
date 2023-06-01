#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  vector<pair<char, int>> pirs;
  for (int i = 0; i < S.size();) {
    // 最初の文字を保持
    char c = S[i];
    int count = 1;

    // 連続する文字をカウント
    i++;
    while (S[i] == c) {
      count++;
      i++;
    }
    pirs.push_back(make_pair(c, count));
  }

  for (auto pir : pirs) {
    cout << pir.first << pir.second;
  }
  cout << endl;
}
