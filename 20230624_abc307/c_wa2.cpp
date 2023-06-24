#include <bits/stdc++.h>
using namespace std;

bool check(vector<pair<int, int>> X, vector<pair<int, int>> A, vector<pair<int, int>> B) {
  set<pair<int, int>> S;
  for (int i = 0; i < A.size(); i++) {
    S.insert(A[i]);
  }
  for (int i = 0; i < B.size(); i++) {
    S.insert(B[i]);
  }

  if (X.size() != S.size()) return false;

  for (int i = 0; i < X.size(); i++) {
    if (!S.count(X[i])) return false;
  }
  return true;
}

int main() {
  int HA, WA;
  cin >> HA >> WA;
  vector<pair<int, int>> A;
  int a_right = 0, a_bottom = 0;
  for (int i = 0; i < HA; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < WA; j++) {
      if (s[j] == '#') {
        A.push_back(make_pair(i, j));
        a_right = max(a_right, j);
        a_bottom = max(a_bottom, i);
      }
    }
  }
  

  int HB, WB;
  cin >> HB >> WB;
  vector<pair<int, int>> B;
  int b_right = 0, b_bottom = 0;
  for (int i = 0; i < HB; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < WB; j++) {
      if (s[j] == '#') {
        B.push_back(make_pair(i, j));
        b_right = max(b_right, j);
        b_bottom = max(b_bottom, i);
      }
    }
  }

  int HX, WX;
  cin >> HX >> WX;
  vector<pair<int, int>> X;
  for (int i = 0; i < HX; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < WX; j++) {
      if (s[j] == '#') X.push_back(make_pair(i, j));
    }
  }

  int inc1 = 0;
  for (int i = 0; i < (HX - a_bottom); i++) {
    int inc2 = 0;
    for (int j = 0; j < (WX - a_right); j++) {
      int inc3 = 0;
      for (int k = 0; k < (HX - b_bottom); k++) {
        int inc4 = 0;
        for (int l = 0; l < (WX - b_right); l++) {
          vector<pair<int, int>> NA = A;
          for (auto &na : NA) {
            na.first += inc1;
            na.second += inc2;
          }
          vector<pair<int, int>> NB = B;
          for (auto &nb : NB) {
            nb.first += inc3;
            nb.second += inc4;
          }
          if (check(X, NA, NB)) {
            cout << "Yes" << endl;
            return 0;
          }
          inc4++;
        }
        inc3++;
      }
      inc2++;
    }
    inc1++;
  }
  cout << "No" << endl;
}