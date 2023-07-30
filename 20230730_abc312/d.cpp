#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// i: i文字目までを使う場合
// j: (と)の数の差
// dp[i][j] = 該当する場合の数のあまり
vector<vector<ll>> dp;
string s;
ll t = 998244353;

ll rec(int y, int x) {
    if (x < 0) {
        return 0;
    }
    if (dp[y][x] != -1) {
        return dp[y][x];
    }

    if (s[y - 1] == '(') {
        dp[y][x] = rec(y - 1, x - 1) % t;
    } else if (s[y - 1] == ')') {
        dp[y][x] = rec(y - 1, x + 1) % t;
    } else if (s[y - 1] == '?') {
        dp[y][x] = rec(y - 1, x + 1) % t + rec(y - 1, x - 1) % t;
    }

    return dp[y][x];
}

int main() {
    cin >> s;
    int n = s.size();

    dp.resize(n + 1, vector<ll>(n + 1, -1));
    for (int i = 0; i < n + 1; i++) {
        dp[0][i] = 0;
    }
    dp[0][0] = 1;
    cout << rec(n, 0) << endl;
}
