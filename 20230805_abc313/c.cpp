#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n ; i++) { 
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    int avg = sum / n;

    long long count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < avg) {
            count1 += avg - a[i];
        } else if (avg + 1 < a[i]) {
            count2 += a[i] - avg - 1;
        }
    }

    cout << max(count1, count2) << endl;
}
