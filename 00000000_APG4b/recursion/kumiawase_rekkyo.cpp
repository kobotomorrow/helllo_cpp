// 組み合わせ列挙(再帰)
// バックトラッキング
#include <bits/stdc++.h>
using namespace std;

// values : 元の要素の配列
// current : 現在選択されている要素のインデックス
// result : 現在の組み合わせ
// selected : 選択された要素の数
// limit : 選択できる要素の数
void combination(vector<int>& values, int current, vector<int>& result, int selected, int limit) {
    cout << "combination(" << current << ", " << selected << ")" << endl;

    // 選択した要素の数が制限に達した場合、組み合わせを出力する
    if (selected == limit) {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }

    // 選択する要素が残っていない場合は、処理を終了する
    if (current >= values.size()) {
        cout << "選択する要素が残っていない" << endl;
        return;
    }

    // current番目の要素を選択する場合
    result[selected] = values[current];
    combination(values, current + 1, result, selected + 1, limit);

    cout << "選択肢しない場合" << endl;

    // current番目の要素を選択しない場合
    combination(values, current + 1, result, selected, limit);
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    int limit = 3;

    vector<int> result(limit);

    combination(values, 0, result, 0, limit);

    return 0;
}
