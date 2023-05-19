// 全探索
// 出力
// 1 1 1 
// 1 1 0 
// 1 0 1 
// 1 0 0 
// 0 1 1 
// 0 1 0 
// 0 0 1 
// 0 0 0 

#include <bits/stdc++.h>
using namespace std;

void dfs(int current, vector<int> &pattern) {
    // すべての要素を選択した場合、パターンを出力する
    if (current == pattern.size()) {
        for (int i = 0; i < pattern.size(); i++) {
            cout << pattern[i] << " ";
        }
        cout << endl;
        return;
    }

    // current番目の要素を選択する場合
    pattern[current] = 1;
    dfs(current + 1, pattern);

    // current番目の要素を選択しない場合
    pattern[current] = 0;
    dfs(current + 1, pattern);
}

int main() {
    int n = 3;
    vector<int> pattern(n, 0); // すべての要素を0で初期化
    dfs(0, pattern); // 0番目の要素から探索を開始する

    return 0;
}
