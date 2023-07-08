#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;

  if ((A % 3 == 1 || A % 3 == 2) && A + 1 == B) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}