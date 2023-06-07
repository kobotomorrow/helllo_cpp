#include <bits/stdc++.h>
using namespace std;

void rec(long long &cur, long long &count, long long &t) {
  // ベースケース
  if (cur == 0) return;

  // 再帰ステップ
  count += pow(2, t);
  cur = cur / 2;
  t++;
  rec(cur, count, t);
}

int main() {
  long long H;
  cin >> H;

  long long count = 0;
  long long t = 0;
  rec(H, count, t);

  cout << count << endl;
}
