#include <bits/stdc++.h>
using namespace std;

bool is_exist_item(pair<long long, long long> &cur, map<long long, set<long long>> &items) {
  auto target_items = items[cur.first];
  for (auto item : target_items) {
    if (item == cur.second) {
      items[cur.first].erase(cur.second);
      return true;
    }
  }
  return false;
}

int main() {
  long long N, M, H, K;
  cin >> N >> M >> H >> K;

  string moves;
  cin >> moves;

  map<long long, set<long long>> items;
  for (long long i = 0; i < M; i++) {
    long long x, y;
    cin >> x >> y;
    items[x].insert(y);
  }

  pair<long long, long long> cur = {0, 0};
  for (long long i = 0; i < N; i++) {
    // 体力消費
    H--;

    // 移動
    if (moves[i] == 'R') cur = {cur.first + 1, cur.second};
    else if (moves[i] == 'L') cur = {cur.first - 1, cur.second};
    else if (moves[i] == 'U') cur = {cur.first, cur.second + 1};
    else if (moves[i] == 'D') cur = {cur.first, cur.second - 1};

    // アイテム取得と回復
    if (H < K && is_exist_item(cur, items)) {
      H = K;
    }

    // 終了判定
    if (H <= 0 && i != N - 1) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
