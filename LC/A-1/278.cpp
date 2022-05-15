// https://leetcode.com/problems/first-bad-version/

#include <iostream>
using namespace std;

class Solution {
 public:
  auto Solve() const -> int;

 public:
  auto Set() -> void;

 private:
  int n = 0;
};

auto Solution::Set() -> void { cin >> n; }

auto Solution::Solve() const -> int {
  // API Provided - CheckBadVersion()
  auto CheckBadVersion = [](const int product) -> bool { return 0; };
  // Binary Search
  uint32_t low = 0, high = n;
  uint32_t position = -1;
  while (low <= high) {
    int product = (low + high) / 2;
    if (CheckBadVersion(product)) {
      high = product - 1;
      position = product;
    } else {
      low = product + 1;
    }
  }
  return position;
}

auto main() -> int {
  Solution S;
  S.Set();
  cout << S.Solve() << '\n';
  return 0;
}
