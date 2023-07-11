#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  int ans = lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
  // これでもOK
  // int ans = ++lower_bound(a.begin(), a.end(), x) - a.begin();
  cout << ans << endl;
}

// lower_bound(a.begin(), a.end(), x) - a.begin()
// イテレータ同士の引き算は、終端の1つ前の要素までの個数を返す
// a.begin()は、先頭の要素を指すイテレータ
// a.end()は、終端の次の要素を指すイテレータ
// つまり、a.end() - a.begin()は、aの要素数となる
// したがって、その要素数は添字と一致する
