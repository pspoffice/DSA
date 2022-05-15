// https://leetcode.com/problems/binary-search/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  auto Solve() -> int;

 private:
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
}

auto Solution::Solve() -> int {
  Set();
  sort(v.begin(), v.end());
  int low = 0, high = size - 1;
  while (low <= high) {
    int index = (low + high) / 2;
    if (x == v[index]) {
      return index;
    } else if (x < v[index]) {
      high = index - 1;
    } else {
      low = index + 1;
    }
  }
  return -1;
}

auto main() -> int {
  Solution S;
  cout << S.Solve() << '\n';
  return 0;
}
