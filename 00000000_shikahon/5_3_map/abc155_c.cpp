#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  // 集計
  map<string, int> S;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    S[s]++;
  }

  // pairに詰め替えてソート(リバース)
  vector<pair<int, string>> P;
  for (auto s : S) {
    P.push_back(make_pair(s.second, s.first));
  }
  sort(P.begin(), P.end());
  reverse(P.begin(), P.end());

  // 最も多いもの(複数可)を配列に詰める
  vector<string> ans;
  int pre = 0;
  for (int i = 0; i < P.size(); i++) {
    if(i == 0) {
      ans.push_back(P[i].second);
      pre = P[i].first;
      continue;
    }
    if (P[i].first == pre) {
      ans.push_back(P[i].second);
      continue;
    }
    break;
  }

  // 辞書順にソートして出力
  sort(ans.begin(), ans.end());
  for (auto s : ans) cout << s << endl;
}
