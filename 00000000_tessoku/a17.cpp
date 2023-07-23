#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> b;
vector<int> dp;
map<int, int> k;

int rec(int x) {
  if (dp[x] != -1) {
    return dp[x];
  }

  int one = rec(x - 1) + a[x - 1];
  int two = rec(x - 2) + b[x - 2];
  dp[x] = min(one, two);
  if (one < two) {
    k[x] = x - 1;
  } else {
    k[x] = x - 2;
  }
  return dp[x];
}

int main() {
  int n;
  cin >> n;

  a.resize(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> a[i];
  }
  b.resize(n - 2);
  for (int i = 0; i < n - 2; i++) {
    cin >> b[i];
  }

  dp.resize(n, -1);
  dp[0] = 0;
  dp[1] = a[0];
  k[1] = 0;

  rec(n - 1);
  
  vector<int> ans;
  ans.push_back(n - 1);
  queue<int> q;
  q.push(n - 1);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    ans.push_back(k[x]);
    if (k[x] == 0) {
      break;
    }
    q.push(k[x]);
  }

  cout << ans.size() << endl;
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] + 1 << " ";
  }
  cout << endl;
}
