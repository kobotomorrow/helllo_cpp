#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int max_c = 0;
  int count = 1;
  int pre = 'R';
  for (int i = 0; i < S.size(); i++) {
    if (i == 0) continue;
    if (S[i] == pre) count++;
    else {
      max_c = max(max_c, count);
      count = 1;
      pre = S[i];
    }
  }

  int ans_c = max_c % 2 == 0 ? max_c : max_c - 1;
  vector<int> ans(S.size(), 1);

  for (int i = 0; i < ans_c; i++) {
    for (int j = 0; j < S.size();) {
      char c = S[j];
      int k;

      bool is_first = true;
      while (S[j] == c && j < S.size() - 1) {
        if (is_first) {
          is_first = false;
          if (c == 'R' && ans[j] == 1) k = j;
          if (c == 'L' && (ans[j] == 0 || j == S.size() - 1)) k = j - 1;
        }
        j++;
      }
      cout << "j: " << j << " k: " << k << endl;

      if (c == 'R') {
        // RLの入れ替え
        ans[j - 1] = ans[j];
        ans[j] = ans[j + 1];
      }
      // RRまたはLLの並びの始めの1を最後のLに移動
      // ただし文字が連続しない場合は例外として考える
      if (j != k) {
        ans[k]--;
        ans[j - 1]++;
      }
      cout << "移動中:";
      for (auto a : ans) cout << a << " ";
      cout << endl;
    }
    cout << i + 1 << "回目の操作後:";
    for (auto a : ans) cout << a << " ";
    cout << endl;
  }
}
