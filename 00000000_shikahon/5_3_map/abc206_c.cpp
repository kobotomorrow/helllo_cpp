#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;

  long long all = N * (N - 1) / 2;

  map<long long, long long> nums;
  for (int i = 0; i < N; i++) {
    long long n;
    cin >> n;
    nums[n]++;
  }

  long long same = 0;
  for (auto n : nums) {
    if (n.second > 1) {
      same += n.second * (n.second - 1) / 2;
    }
  }

  cout << all - same << endl;
}
