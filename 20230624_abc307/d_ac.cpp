#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  string ans;
  vector<int> A;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == '(') {
      ans += S[i];
      A.push_back(i);
    } else if (S[i] == ')') {
      if (A.size() == 0) {
        ans += S[i];
      } else {
        while (ans.back() != '(') {
          ans.pop_back();
        }
        ans.pop_back();
        A.pop_back();
      }
    } else {
      ans += S[i];
    }
  }
  cout << ans << endl;
}