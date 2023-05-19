#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> t_count;
  vector<int> a_count;

  int h = s.size() / 2;

  char t = 'A';
  bool flag = false;

  for (char c : s) {
    if (c == 'T') {
      t_count.push_back(1);
    } else {
      a_count.push_back(1);
    }

    if (t_count.size() == h && !flag) {
      t = 'T';
      flag = true;
    }

    if (a_count.size() == h && !flag) {
      t = 'A';
      flag = true;
    }
  }

  if (t_count.size() > a_count.size()) {
    cout << 'T' << endl;
  } else if (t_count.size() == a_count.size() && t == 'T') {
    cout << 'T' << endl;
  } else if (t_count.size() == a_count.size() && t == 'A') {
    cout << 'A' << endl;
  } else {
    cout << 'A' << endl;
  }
}