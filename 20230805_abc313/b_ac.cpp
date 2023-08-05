#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> ab;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ab[a].push_back(b);
    }

    for (int i = 1; i < n+1; i++) {
        queue<int> q;
        set<int> visited;
        q.push(i);
        visited.insert(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int j = 0; j < ab[cur].size(); j++) {
                if (visited.count(ab[cur][j]) == 0) {
                    int next = ab[cur][j];
                    q.push(next);
                    visited.insert(next);
                }
            }
        }
        if (visited.size() == n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
