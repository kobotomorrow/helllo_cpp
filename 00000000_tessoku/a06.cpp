#include <bits/stdc++.h>
using namespace std;

int H, W;
map<char, char> snk;
vector<string> S;
vector<vector<bool>> visited;

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<int> A(N);
  for (auto &a : A) cin >> a;

  vector<long long> sum(N + 1);

  long long subtotal = 0;
  sum[0] = 0;
  for (int i = 1; i <= N; i++) {
    subtotal += A[i - 1];
    sum[i] = subtotal;
  }

  for (int i = 0; i < Q; i++) {
    int start, end;
    cin >> start >> end;
    cout << sum[end] - sum[start - 1] << endl;
  }
}
