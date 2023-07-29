#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> v = { "ACE","BDF","CEG","DFA","EGB","FAC","GBD" };
    string s;
    cin >> s;

    for (auto vv : v) {
        if (vv == s) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
