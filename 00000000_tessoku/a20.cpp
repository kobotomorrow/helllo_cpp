#include <bits/stdc++.h>
using namespace std;

string S;
string T;
vector<vector<int>> dp;

int rec(int y, int x) {
    if (dp[y][x] != -1) {
        return dp[y][x];
    }
    if (y == 0 || x == 0) {
        return dp[y][x] = 0;
    }

    int a = rec(y - 1, x);
    int b = rec(y, x - 1);
    int c = 0;
    if (S[y - 1] == T[x - 1]) {
        c = rec(y - 1, x - 1) + 1;
    }
    return dp[y][x] = max({a, b, c});
}

int main() {
    cin >> S >> T;
    dp.resize(S.size() + 1, vector<int>(T.size() + 1, -1));
    cout << rec(S.size(), T.size()) << endl;
}
