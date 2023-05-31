#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  set<int> S;

  int pre_size = 0;
  for (int i = 0; i < N; i++) {
    int s;
    cin >> s;
    S.erase(s);

    if (S.size() == pre_size) {
      S.insert(s);
    }

    pre_size = S.size();
  }

  cout << S.size() << endl;
}
