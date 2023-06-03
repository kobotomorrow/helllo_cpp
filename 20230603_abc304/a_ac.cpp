#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<pair<int, string>> H(N);
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i].second >> H[i].first;
  }

  int min = 0;
  for (int i = 0; i < N; i++) {
    if (H[i].first < H[min].first) {
      min = i;
    }
  }

  for (int i = min; i < N; i++) {
    cout << H[i].second << endl;
  }
  for (int i = 0; i < min; i++) {
    cout << H[i].second << endl;
  }
}
