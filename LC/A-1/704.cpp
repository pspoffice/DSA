// https://leetcode.com/problems/binary-search/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  auto Search() const -> int;

  auto FirstOccurrence() const -> int;

  auto LastOccurrence() const -> int;

 public:
  auto Set() -> void;

 private:
  int x = 0;
  int size = 0;
  vector<int> v;
};

auto Solution::Set() -> void {
  cin >> x;  // Target
  cin >> size;
  v.resize(size);
  for (size_t i = 0; i < v.size(); i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
}

auto Solution::Search() const -> int {
  int low = 0, high = size - 1;
  while (low <= high) {
    int index = (low + high) / 2;
    if (x == v[index]) {
      return index;
    } else if (x > v[index]) {
      low = index + 1;
    } else {
      high = index - 1;
    }
  }
  return -1;
}

auto Solution::FirstOccurrence() const -> int {
  int low = 0, high = size - 1;
  int position = -1;
  while (low <= high) {
    int index = (low + high) / 2;
    if (v[index] == x) {
      position = index;
      high = index - 1;
    } else if (x > v[index]) {
      low = index + 1;
    } else {
      high = index - 1;
    }
  }
  return position;
}

auto Solution::LastOccurrence() const -> int {
  int low = 0, high = size - 1;
  int position = -1;
  while (low <= high) {
    int index = (low + high) / 2;
    if (v[index] == x) {
      position = index;
      low = index + 1;
    } else if (x > v[index]) {
      low = index + 1;
    } else {
      high = index - 1;
    }
  }
  return position;
}

auto main() -> int {
  Solution S;
  S.Set();
  cout << S.Search() << '\n'
       << S.FirstOccurrence() << '\n'
       << S.LastOccurrence() << '\n';
  return 0;
}
