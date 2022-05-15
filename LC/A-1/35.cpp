// https://leetcode.com/problems/search-insert-position/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  auto Solve() const -> int;

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

auto Solution::Solve() const -> int {
  int index = 0;
  int low = 0, high = size - 1;
  while (low <= high) {
    index = (low + high) / 2;
    if (x == v[index]) {
      return index;
    } else if (x > v[index]) {
      low = index + 1;
    } else {
      high = index - 1;
    }
  }
  return (x > v[index] ? ++index : index);
}

auto main() -> int {
  Solution S;
  S.Set();
  cout << S.Solve() << endl;
  return 0;
}
