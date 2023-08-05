#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());

    long long cur = 0;
    for (int i = 0; i < n; i++) {
        long long move = a[i].first - cur;
        if (k - move < 0) {
            break;
        } else {
            k -= move;
            cur = a[i].first;
        }
        k += a[i].second;
    }
    cur += k;

    cout << cur << endl;
}
