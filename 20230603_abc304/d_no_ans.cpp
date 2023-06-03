#include <bits/stdc++.h>
using namespace std;

int main() {
  int W, H, N;
  cin >> W >> H >> N;

  // いちご
  vector<pair<int, int>> I(N);
  for (int i = 0; i < N; i++) {
    cin >> I[i].first >> I[i].second;
  }

  // y軸に平行な線
  int A;
  cin >> A;
  vector<int> AL;
  for (auto &al : AL) cin >> al;

  // x軸に平行な線
  int B;
  cin >> B;
  vector<int> BL;
  for (auto &bl : BL) cin >> bl;

  vector<int> ans((A + 1) * (B + 1), 0);
}
