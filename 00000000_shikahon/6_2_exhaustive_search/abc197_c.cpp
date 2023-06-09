#include <bits/stdc++.h>
using namespace std;

int N;
vector<long long> A;

void rec(int current, vector<bool> &pettern, long long &result) {
  // ベースケース
  if (current == pettern.size()) {
    vector<vector<long long>> num;
    num.push_back({A[0]});
    int j = 0;
    for (int i = 0; i < pettern.size(); i++) {
      if (pettern[i]) {
        num.push_back({A[i + 1]});
        j++;
      } else {
        num[j].push_back(A[i + 1]);
      }
    }
    vector<long long> or_num(num.size());
    for (int i = 0; i < num.size(); i++) {
      long long t = 0;
      for (int j = 0; j < num[i].size(); j++) {
        if (j == 0) t = num[i][j];
        else t = t | num[i][j];
      }
      or_num[i] = t;
    }

    long long u;
    for (int i = 0; i < or_num.size(); i++) {
      if (i == 0) u = or_num[i];
      else u = u ^ or_num[i];
    }

    result = min(result, u);
    return;
  }

  // 再帰ステップ
  pettern[current] = true;
  rec(current + 1, pettern, result);

  pettern[current] = false;
  rec(current + 1, pettern, result);
}

int main() {
  cin >> N;
  A.resize(N);
  for (auto &a : A) cin >> a;

  vector<bool> pettern(N - 1, false);
  long long result = 1e18;
  rec(0, pettern, result);

  cout << result << endl;
}
