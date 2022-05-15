// https://leetcode.com/problems/search-insert-position/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  auto UpperBound() const -> int;

  auto LowerBound() const -> int;

 public:
  auto Set() -> void;

 private:
  int x = 0;
  int size = 0;
  vector<int> v;
};

auto Solution::Set() -> void {
  cin >> x;
  cin >> size;
  v.resize(size);
  for (size_t i = 0; i < v.size(); i++) {
    cin >> v[i];
  }
}

auto Solution::LowerBound() const -> int {
  int position = size;
  int low = 0, high = size - 1;
  while (low <= high) {
    int index = (low + high) / 2;
    if (x <= v[index]) {
      position = index;
      high = index - 1;
    } else {
      low = index + 1;
    }
  }
  return position;
}

auto Solution::UpperBound() const -> int {
  int position = size;
  int low = 0, high = size - 1;
  while (low <= high) {
    int index = (low + high) / 2;
    if (x >= v[index]) {
      low = index + 1;
    } else {
      position = index;
      high = index - 1;
    }
  }
  return position;
}

auto main() -> int {
  Solution S;
  S.Set();
  cout << S.LowerBound() << endl;
  cout << S.UpperBound() << endl;
  return 0;
}
