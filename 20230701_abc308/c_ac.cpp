#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<pair<long double, int>> AB(N);
  for (int i = 0; i < N; i++) {
    long double A, B;
    cin >> A >> B;
    AB[i].first = A / (B + A);
    AB[i].second = i + 1;
  }

  sort(AB.begin(), AB.end(), [](auto a, auto b) {
    if (a.first == b.first) {
      return a.second < b.second;
    } else {
      return a.first > b.first;
    }
  });

  for (int i = 0; i < N; i++) {
    cout << AB[i].second << " ";
  }
  cout << endl;
}
