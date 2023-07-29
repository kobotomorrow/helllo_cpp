#include <bits/stdc++.h>
using namespace std;

vector<string> s;

#include <bits/stdc++.h>
using namespace std;

int urite(int x, vector<int> &a) {
    if (x < a[0]) return 0;
    if (x > a.back()) return a.size();
    return upper_bound(a.begin(), a.end(), x) - a.begin();
}

int kaite(int x, vector<int> &b) {
    return b.end() - lower_bound(b.begin(), b.end(), x);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int l = 0;
    int r = 1e9 + 1;
    int mid = 0;
    while (l < r) {
        mid = (l + r) / 2;
        if (urite(mid, a) >= kaite(mid, b)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
}
