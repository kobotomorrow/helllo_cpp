#include <bits/stdc++.h>
using namespace std;

struct int_variable {
  string name;
  int value;
};

vector<int_variable> int_variables;

struct vector_variable {
  string name;
  vector<int> values;
};

vector<vector_variable> vector_variables;

void print_vec(vector<int> vec) {
  cout << "[ ";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i) << " ";
  }
  cout << "]" << endl;
}

void print_int(int x) {
  cout << x << endl;
}

int_variable find_int_variable(string name) {
  int_variable target;
  for (auto iv : int_variables) {
    if (iv.name == name) {
      target = iv;
      break;
    }
  }
  return target;
}

vector_variable find_vector_variable(string name) {
  vector_variable target;
  for (auto vv : vector_variables) {
    if (vv.name == name) {
      target = vv;
      break;
    }
  }
  return target;
}

int main() {
  int n;
  cin >> n;

  vector<vector<string>> statement(n);

  for (int i = 0; i < n; i++) {
    while (true) {
      string s;
      cin >> s;

      if (s == ";") break;

      statement.at(i).push_back(s);
    }
  }

  for (int i = 0; i < n; i++) {
    // int式
    if (statement.at(i).at(0) == "int") {
      int total = 0;
      char pre_op;

      for (int j = 3; j < statement.at(i).size(); j++) {
        if (j == 3) {
          if (isdigit(statement.at(i).at(3).at(0))) total = stoi(statement.at(i).at(3));
          else total = find_int_variable(statement.at(i).at(3)).value;
        } else if (j % 2 == 1) {
          int value = 0;
          if (isdigit(statement.at(i).at(j).at(0))) value = stoi(statement.at(i).at(j));
          else value = find_int_variable(statement.at(i).at(j)).value;

          if (pre_op == '+') total += value;
          else total -= value;
        } else  {
          pre_op = statement.at(i).at(j).at(0);
        }
      }
      int_variable iv = {statement.at(i).at(1), total};
      int_variables.push_back(iv);
    }
    // print_int
    else if (statement.at(i).at(0) == "print_int") {
      int total = 0;
      char pre_op;

      for (int j = 1; j < statement.at(i).size(); j++) {
        if (j == 1) {
          if (isdigit(statement.at(i).at(j).at(0))) total = stoi(statement.at(i).at(1));
          else total = find_int_variable(statement.at(i).at(1)).value;
        } else if (j % 2 == 1) {
          int value = 0;
          if (isdigit(statement.at(i).at(j).at(0))) value = stoi(statement.at(i).at(j));
          else value = find_int_variable(statement.at(i).at(j)).value;

          if (pre_op == '+') total += value;
          else total -= value;
        } else  {
          pre_op = statement.at(i).at(j).at(0);
        }
      }
       print_int(total);
    }
    // print_vec
    else if (statement.at(i).at(0) == "print_vec") {
      vector<int> vec;
      bool is_plus = false;
      bool is_minus = false;
      int plus_count = 0;
      int minus_count = 0;

      for (int j = 1; j < statement.at(i).size(); j++) {
        if (statement.at(i).at(j) == "[") continue;
        if (statement.at(i).at(j) == ",") continue;
        if (statement.at(i).at(j) == "]") {
          is_plus = false;
          is_minus = false;
          plus_count = 0;
          minus_count = 0;
          continue;
        };
        if (statement.at(i).at(j).at(0) == '+') {
          is_plus = true;
          continue;
        }
        if (statement.at(i).at(j).at(0) == '-') {
          is_minus = true;
          continue;
        }
        if (is_plus) {
          if (isdigit(statement.at(i).at(j).at(0))) {
            vec.at(plus_count) += statement.at(i).at(j).at(0) - '0';
            plus_count++;
            continue;
          } else if (statement.at(i).at(j - 1).at(0) == '[' || statement.at(i).at(j - 1).at(0) == ',') {
            int_variable iv = find_int_variable(statement.at(i).at(j));
            vec.at(plus_count) += iv.value;
            plus_count++;
            continue;
          } else {
            vector_variable vv = find_vector_variable(statement.at(i).at(j));
            for (int k = 0; k < vv.values.size(); k++) {
              vec.at(k) += vv.values.at(k);
            }
            is_plus = false;
            is_minus = false;
            plus_count = 0;
            minus_count = 0;
            continue;
          }
        }
        if (is_minus) {
          if (isdigit(statement.at(i).at(j).at(0))) {
            vec.at(minus_count) -= statement.at(i).at(j).at(0) - '0';
            minus_count++;
          } else if (statement.at(i).at(j - 1).at(0) == '[' || statement.at(i).at(j - 1).at(0) == ',') {
            int_variable iv = find_int_variable(statement.at(i).at(j));
            vec.at(minus_count) -= iv.value;
            minus_count++;
            continue;
          } else {
            vector_variable vv = find_vector_variable(statement.at(i).at(j));
            for (int k = 0; k < vv.values.size(); k++) {
              vec.at(k) -= vv.values.at(k);
            }
            is_plus = false;
            is_minus = false;
            plus_count = 0;
            minus_count = 0;
          }
          continue;
        }

        // 式の一番最初の項
        if (isdigit(statement.at(i).at(j).at(0))) vec.push_back(stoi(statement.at(i).at(j)));
        else if (statement.at(i).at(j - 1).at(0) == '[' || statement.at(i).at(j - 1).at(0) == ',') vec.push_back(find_int_variable(statement.at(i).at(j)).value);
        else vec = find_vector_variable(statement.at(i).at(j)).values;
      }
      print_vec(vec);
    }
    // vec式
    else if (statement.at(i).at(0) == "vec") {
      vector<int> vec;
      bool is_plus = false;
      bool is_minus = false;
      int plus_count = 0;
      int minus_count = 0;

      for (int j = 3; j < statement.at(i).size(); j++) {
        if (statement.at(i).at(j) == "[") continue;
        if (statement.at(i).at(j) == ",") continue;
        if (statement.at(i).at(j) == "]") {
          is_plus = false;
          is_minus = false;
          plus_count = 0;
          minus_count = 0;
          continue;
        };
        if (statement.at(i).at(j).at(0) == '+') {
          is_plus = true;
          continue;
        }
        if (statement.at(i).at(j).at(0) == '-') {
          is_minus = true;
          continue;
        }
        if (is_plus) {
          if (isdigit(statement.at(i).at(j).at(0))) {
            vec.at(plus_count) += statement.at(i).at(j).at(0) - '0';
            plus_count++;
          } else if (statement.at(i).at(j - 1).at(0) == '[' || statement.at(i).at(j - 1).at(0) == ',') {
            int_variable iv = find_int_variable(statement.at(i).at(j));
            vec.at(plus_count) += iv.value;
            plus_count++;
            continue;
          } else {
            vector_variable vv = find_vector_variable(statement.at(i).at(j));
            for (int k = 0; k < vv.values.size(); k++) {
              vec.at(k) += vv.values.at(k);
            }
            is_plus = false;
            is_minus = false;
            plus_count = 0;
            minus_count = 0;
          }
          continue;
        }
        if (is_minus) {
          if (isdigit(statement.at(i).at(j).at(0))) {
            vec.at(minus_count) -= statement.at(i).at(j).at(0) - '0';
            minus_count++;
          }  else if (statement.at(i).at(j - 1).at(0) == '[' || statement.at(i).at(j - 1).at(0) == ',') {
            int_variable iv = find_int_variable(statement.at(i).at(j));
            vec.at(minus_count) -= iv.value;
            minus_count++;
            continue;
          } else {
            vector_variable vv = find_vector_variable(statement.at(i).at(j));
            for (int k = 0; k < vv.values.size(); k++) {
              vec.at(k) -= vv.values.at(k);
            }
            is_plus = false;
            is_minus = false;
            plus_count = 0;
            minus_count = 0;
          }
          continue;
        }

        // 式の一番最初の項
        if (isdigit(statement.at(i).at(j).at(0))) vec.push_back(stoi(statement.at(i).at(j)));
        else if (statement.at(i).at(j - 1).at(0) == '[' || statement.at(i).at(j - 1).at(0) == ',') vec.push_back(find_int_variable(statement.at(i).at(j)).value);
        else vec = find_vector_variable(statement.at(i).at(j)).values;
      }
      vector_variable vv = {statement.at(i).at(1), vec};
      vector_variables.push_back(vv);
    }
  }
}
