#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<int> weight(n), v(n);
    for (int i = 0; i < n; i++) {
        int ww, vv;
        cin >> ww >> vv;
        weight[i] = ww;
        v[i] = vv;
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(w + 1, 0));
    long long mx = 0;

    for (int i = 1; i <= n; i++) {
        dp[i][weight[i - 1]] = v[i - 1];
        for (int j = 0; j <= w; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j - weight[i - 1] >= 0 && dp[i - 1][j - weight[i - 1]] > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i - 1]] + v[i - 1]);
            }
            mx = max(mx, dp[i][j]);
        }
    }

    cout << mx << endl;
}
