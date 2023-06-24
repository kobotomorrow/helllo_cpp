#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<vector<long long>> A(N, vector<long long>(7));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 7; j++) {
      cin >> A.at(i).at(j);
    }
  }

  vector<long long> ans(N);
  for (int i = 0; i < N; i++) {
    long long sum = 0;
    for (int j = 0; j < 7; j++) {
      sum += A.at(i).at(j);
    }
    ans.at(i) = sum;
  }

  for (int i = 0; i < N; i++) {
    cout << ans.at(i) << " ";
  }
  cout << endl;
}