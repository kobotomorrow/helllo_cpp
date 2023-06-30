#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;

  vector<int> A(N);
  for (auto &a : A) cin >> a;

  vector<int> SA;
  set<int> searched;
  int loop_number = 0;
  SA.push_back(1);
  searched.insert(1);
  int next = 0;
  while (searched.count(A[next]) == 0) {
    SA.push_back(A[next]);
    searched.insert(A[next]);
    next = A[next] - 1;
    loop_number = A[next];
  }

  vector<int> LA;
  int minus_count = 0;
  bool is_loop = false;
  for (unsigned long long i = 0; i < SA.size(); i++) {
    if (SA[i] == loop_number) is_loop = true;
    if (is_loop) {
      LA.push_back(SA[i]);
    } else {
      minus_count++;
    }
  }

  vector<int> M(LA.size());
  for (unsigned long long i = 0; i < LA.size(); i++) {
    M[i] = i % SA.size();
  }

  if (LA.size() == 0) {
    cout << A[0] << endl;
    return 0;
  }

  if (K <= minus_count) {
    cout << SA[K] << endl;
  } else {
    cout << LA[(K - minus_count) % LA.size()] << endl;
  }
}