#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  map<int, int> mp;
  for (int i = 1; i <= N; i++) mp[i] = 0;

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    mp[a]++;
    mp[b]++;
  }

  for (auto m : mp) cout << m.second << endl;
}
