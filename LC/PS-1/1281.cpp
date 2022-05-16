// https://leetcode.com/problems/number-of-1-bits/

#include <iostream>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(nullptr)

class Solution {
 public:
  auto SubtractProductAndSum() const -> int;

  auto Set() -> void;

 private:
  int x = 0;
};

auto Solution::Set() -> void { cin >> x; }

auto Solution::SubtractProductAndSum() const -> int {
  uint64_t a = 1, b = 0;
  int c = x;
  while (c) {
    const int d = c % 10;
    a *= d;
    b += d;
    c /= 10;
  }
  return (a - b);
}

auto main() -> int {
  FAST;
  Solution S;
  S.Set();
  cout << S.SubtractProductAndSum() << '\n';
}
