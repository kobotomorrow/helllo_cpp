#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, W;
  cin >> A >> B >> W;
  W *= 1000;

  int min_num = 0;
  if (W % B == 0) {
    min_num = W / B;
  } else {
    min_num = W / B + 1;
  }
  int max_num = W / A;

  vector<int> ans;
  for (int i = min_num; i <= max_num; i++) {
    if (A * i <= W && W <= B * i) {
      ans.push_back(i);
    }
  }

  if (ans.empty()) {
    cout << "UNSATISFIABLE" << endl;
    return 0;
  }

  sort(ans.begin(), ans.end());

  cout << ans[0] << " " << ans[ans.size() - 1] << endl;
}
