#include <bits/stdc++.h>
using namespace std;

int n, k;

bool is_ok(int x, vector<vector<int>> &a, int center) {
    vector t(n+1, vector<int>(n+1));
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; ++j) {
            t[i][j] = a[i-1][j-1] > x ? 1 : 0;
        }
    }
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            t[i][j] += t[i-1][j];
        }
    }
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; ++j) {
            t[i][j] += t[i][j-1];
        }
    }
    for (int i = 0; i < n-k+1; i++) {
        for (int j = 0; j < n-k+1; j++) {
            int e = t[i+k][j+k];
            e -= t[i][j+k];
            e -= t[i+k][j];
            e += t[i][j];

            if (e < center) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    int center = k*k/2 + 1;

    int l = -1, r = 1000000001;
    while (l+1 < r) {
        int m = (l+r)/2;
        if(is_ok(m, a, center)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;
}
