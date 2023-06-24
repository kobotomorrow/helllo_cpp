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

    cout << "A" << endl;
  for (int i = 0; i < A.size(); i++) {
    cout << A[i].first << " " << A[i].second << endl;
  }
  cout << "B" << endl;
  for (int i = 0; i < B.size(); i++) {
    cout << B[i].first << " " << B[i].second << endl;
  }

  cout << "X" << endl;
  for (int i = 0; i < X.size(); i++) {
    cout << X[i].first << " " << X[i].second << endl;
  }
  cout << "S" << endl;
  for (auto s : S) {
    cout << s.first << " " << s.second << endl;
  }
  cout << endl;

  if (X.size() != S.size()) return false;

  for (int i = 0; i < X.size(); i++) {
    if (!S.count(X[i])) return false;
  }
  return true;
}

void increment_first(vector<pair<int, int>> &V) {
  for (int i = 0; i < V.size(); i++) {
    V[i].first++;
  }
}

void increment_second(vector<pair<int, int>> &V) {
  for (int i = 0; i < V.size(); i++) {
    V[i].second++;
  }
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

  for (int i = 0; i < (HX - a_bottom); i++) {
    for (int j = 0; j < (WX - a_right); j++) {
      for (int k = 0; k < (HX - b_bottom); k++) {
        cout << "テスト" << endl;
        for (int l = 0; l < (WX - b_right); l++) {
          if (check(X, A, B)) {
            cout << "Yes" << endl;
            return 0;
          }
          increment_second(B);
        }
        increment_first(B);
      }
      increment_second(A);
    }
    increment_first(A);
  }
  cout << "No" << endl;
}