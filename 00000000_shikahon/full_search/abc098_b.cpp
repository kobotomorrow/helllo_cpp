#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  int max = 0;

  for (int len = 1; len < N; len++) {
    string S1 = S.substr(0, len);
    string S2 = S.substr(len, N - len);

    set<char> s1;
    set<char> s2;
    for (char c : S1) s1.insert(c);
    for (char c : S2) s2.insert(c);

    set<char> s3;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.end()));

    if (max < s3.size()) max = s3.size();
  }

  cout << max << endl;
}
