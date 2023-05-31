#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  map<char, int> ans;
  for (int c = 'a'; c <= 'z'; c++) {
    ans[c] = 0;
  }

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;

    // 各文字列ごとに集計
    map<char, int> cnt;
    for (auto c : s) cnt[c]++;

    // ansを最小値で更新
    for (int c = 'a'; c <= 'z'; c++) if (i == 0 || ans[c] > cnt[c]) ans[c] = cnt[c];
  }

  for (auto a : ans) {
    if (a.second == 0) continue;
    for (int i = 0; i < a.second; i++) cout << a.first;
  }

  cout << endl;
}
