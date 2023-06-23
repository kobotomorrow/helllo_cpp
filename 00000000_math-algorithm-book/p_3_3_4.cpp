#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  map<long long, long long> A;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[a]++;
  }

  cout << A[100] * A[400] + A[200] * A[300] << endl;
}