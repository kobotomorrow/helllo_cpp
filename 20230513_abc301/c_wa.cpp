// AC回答例
// https://drken1215.hatenablog.com/entry/2023/05/14/001500


#include <bits/stdc++.h>
using namespace std;

int main() {
  string s1;
  string s2;
  cin >> s1 >> s2;

  for (int i = 0; i < s1.size(); i++) {
    char c1 = s1.at(i);

    if (c1 == '@') {
      continue;
    }
    
    for (int j = 0; j < s2.size(); j++) {
      char c2 = s2.at(j);

      if (c1 == c2) {
        s1.erase(i, 1);
        s2.erase(j, 1);
        i--;
        j--;
        break;
      } else if (c2 == '@' && (c1 == '@' || c1 == 'a' || c1 == 't' || c1 == 'c' || c1 == 'o' || c1 == 'd' || c1 == 'e' || c1 == 'r')) {
        s1.erase(i, 1);
        s2.erase(j, 1);
        i--;
        j--;
        break;
      }
    }
  }

  for (int i = 0; i < s1.size(); i++) {
    char c1 = s1.at(i);

    for (int j = 0; j < s2.size(); j++) {
      char c2 = s2.at(j);

      if (c1 == '@' && (c2 == '@' || c2 == 'a' || c2 == 't' || c2 == 'c' || c2 == 'o' || c2 == 'd' || c2 == 'e' || c2 == 'r')) {
        s1.erase(i, 1);
        s2.erase(j, 1);
        i--;
        j--;
        break;
      }
    }
  }

  if (s1.size() == 0 && s2.size() == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}