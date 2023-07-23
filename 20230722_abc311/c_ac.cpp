#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  map<int, int> a;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[i] = x;
  }

  queue<int> q;
  q.push(1);
  vector<int> visited;
  set<int> visited_set;
  visited.push_back(1);
  visited_set.insert(1);
  int target_idx = -1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();

    int mm = a[x];
    if (visited_set.count(mm) > 0) {
      target_idx = find(visited.begin(), visited.end(), mm) - visited.begin();
      break;
    } else {
      visited.push_back(mm);
      visited_set.insert(mm);
      q.push(mm);
    }
  }

  cout << visited.size() - target_idx << endl;
  for (int i = target_idx; i < visited.size(); i++) {
    cout << visited[i] << " ";
  }
  cout << endl;
}
