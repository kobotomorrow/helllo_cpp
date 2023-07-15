#include <bits/stdc++.h>
using namespace std;

double f(double x) {
  return x * x * x + x;
}

int main() {
  int n;
  cin >> n;

  double l = 0, r = 100, m = 0;
  for (int i = 0; i < 20; i++) {
    m = (l + r) / 2.0;
    double v = f(m);

    if (v > n * 1.0) {
      r = m;
    } else {
      l = m;
    }
  }

  printf("%.12lf\n", m);
}
