#include <bits/stdc++.h>
using namespace std;

vector<string> s;

bool tak_code(int nn, int mm) {
    for (int i = 0; i < 9; i++) {
        if (i == 4) continue;
        for (int j = 0; j < 9; j++) {
            if (i == 0 || i == 1 || i == 2) {
                if (j == 0 || j == 1 || j == 2) {
                    if (s[nn + i][mm + j] != '#') return false;
                }
                if (j == 3) {
                    if (s[nn + i][mm + j] != '.') return false;
                }
            }
            if (i == 3) {
                if (j == 0 || j == 1 || j == 2 || j == 3) {
                    if (s[nn + i][mm + j] != '.') return false;
                }
            }
            if (i == 5) {
                if (j == 5 || j == 6 || j == 7 || j == 8) {
                    if (s[nn + i][mm + j] != '.') return false;
                }
            }
            if (i == 6 || i == 7 || i == 8) {
                if (j == 6 || j == 7 || j == 8) {
                    if (s[nn + i][mm + j] != '#') return false;
                }
                if (j == 5) {
                    if (s[nn + i][mm + j] != '.') return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    s.resize(n);
    for (auto &ss : s) cin >> ss;

    for (int i = 0; i < n - 8; i++) {
        for (int j = 0; j < m - 8; j++) {
            if (tak_code(i, j)) {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
}
