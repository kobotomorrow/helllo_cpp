#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A(200009);
vector<int> C(200009);

void merge_sort(int l, int r) {
  if (r - l == 1) return;

  int m = (l + r) / 2;
  merge_sort(l, m);
  merge_sort(m, r);

  int c1 = l;
  int c2 = m;
  int count = 0;

  while (c1 != m || c2 != r) {
    if (c1 == m) {
      C[count] = A[c2];
      c2++;
    } else if (c2 == r) {
      C[count] = A[c1];
      c1++;
    } else {
      if (A[c1] < A[c2]) {
        C[count] = A[c1];
        c1++;
      } else {
        C[count] = A[c2];
        c2++;
      }
    }
    count++;
  }

  for (int i = 0; i < count; i++) {
    A[l + i] = C[i];
  }
}

int main() {
  cin >> N;
  A.resize(N);
  C.resize(N);
  for (auto &a : A) cin >> a;

  merge_sort(0, N);
  for (auto a : A) cout << a << " ";
  cout << endl;
}