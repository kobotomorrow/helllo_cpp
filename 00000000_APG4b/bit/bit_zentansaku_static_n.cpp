#include <bits/stdc++.h>
using namespace std;

int main() {
  // 3ビットのビット列をすべて列挙する
  // 1 << 3 : 1を3ビット左シフトすると8になる
  for (int tmp = 0; tmp < (1 << 3); tmp++) {
    bitset<3> s(tmp);
    // ビット列を出力
    cout << s << endl;
  }
}