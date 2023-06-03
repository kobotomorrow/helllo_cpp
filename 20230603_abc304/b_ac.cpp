#include <bits/stdc++.h>
using namespace std;

long long p3 = pow(10, 3);
long long p4 = pow(10, 4);
long long p5 = pow(10, 5);
long long p6 = pow(10, 6);
long long p7 = pow(10, 7);
long long p8 = pow(10, 8);
long long p9 = pow(10, 9);

int main() {
  long long N;
  cin >> N;

  if (N <= p3 - 1) {
    cout << N << endl;
    return 0;
  }

  if (p3 <= N && N <= p4 - 1) {
    cout << N / 10 * 10 << endl;
    return 0;
  }

  if (p4 <= N && N <= p5 - 1) {
    cout << N / 100 * 100 << endl;
    return 0;
  }

  if (p5 <= N && N <= p6 - 1) {
    cout << N / 1000 * 1000 << endl;
    return 0;
  }

  if (p6 <= N && N <= p7 - 1) {
    cout << N / 10000 * 10000 << endl;
    return 0;
  }

  if (p7 <= N && N <= p8 - 1) {
    cout << N / 100000 * 100000 << endl;
    return 0;
  }

  if (p8 <= N && N <= p9 - 1) {
    cout << N / 1000000 * 1000000 << endl;
    return 0;
  }
}
