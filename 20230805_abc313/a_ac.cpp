#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> p(n-1);
    int f = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            cin >> f;
            continue;
        }
        cin >> p[i-1];
    }
    sort(p.begin(), p.end());
    int ans = p[n-2] - f;
    if (ans < 0) cout << 0 << endl;
    else cout << ans + 1 << endl;
}
