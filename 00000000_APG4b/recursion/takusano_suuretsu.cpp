// https://atcoder.jp/contests/abc045/tasks/arc061_a
#include <bits/stdc++.h>
using namespace std;

int64_t calc(string s, vector<int> &plus_index_list) {
  int plus_count = 0;

  for (int i = 0; i < plus_index_list.size(); i++) {
    s.insert(plus_index_list[i] + plus_count, "+");
    plus_count++;
  }

  int64_t total = 0;
  string num = "";
  for (int i = 0; i < s.size(); i++) {
    if (s.at(i) == '+') {
      total += stoll(num);
      num = "";
    } else {
      num += s.at(i);

      if (i == s.size() - 1) {
        total += stoll(num);
      }
    }
  }
  return total;
}

void combination(vector<int> &values, vector<int> &result, vector<vector<int>> &results, int current, int selected, int limit) {
  if (selected == limit) {
    results.push_back(result);
    return;
  }

  if (current >= values.size()) {
    return;
  }

  result[selected] = values[current];
  combination(values, result, results, current + 1, selected + 1, limit);

  combination(values, result, results, current + 1, selected, limit);
}

int64_t subtotal(string s, int selected_line_num) {
  if (selected_line_num == 0) {
    return stoll(s);
  }

  vector<int> values(s.size() - 1);
  for (int i = 1; i <= s.size() - 1; i++) {
    values[i - 1] = i;
  }
  vector<int> result(selected_line_num);
  vector<vector<int>> results;

  combination(values, result, results, 0, 0, selected_line_num);

  int64_t total = 0;
  for (vector<int> r : results) {
    total += calc(s, r);
  }

  return total;
}

int main() {
  string s;
  cin >> s;

  int64_t total = 0;
  for (int i = 0; i < s.size(); i++) {
    int64_t t = subtotal(s, i);
    total += t;
  }

  cout << total << endl;
}