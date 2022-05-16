// https://leetcode.com/problems/number-of-1-bits/

#include <iostream>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(nullptr)

class Solution {
 public:
  auto Solve() -> int;

 private:
  uint32_t x = 0;
};

auto Solution::Solve() -> int {
  cin >> x;
  int16_t count = 0;
  while (x) {
    count += (x & 1);
    x >>= 1;
  }
  return count;
}

auto main() -> int {
  FAST;
  Solution S;
  cout << S.Solve() << '\n';
}
