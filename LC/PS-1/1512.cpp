// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

#include <iostream>
using namespace std;

class Solution {
 public:
  auto Solve() -> int;

 private:
  auto Set() -> void;

 private:
  int low = 0, high = 0;
};

void Solution::Set() { cin >> low >> high; }

int Solution::Solve() {
  Set();
  auto count = 0;
  const bool a = (low % 2 == 0);
  const bool b = (high % 2 == 0);
  if (a and b) {
    count = (high - low) / 2;
  } else {
    count = (high - low) / 2 + 1;
  }
  return count;
}

auto main() -> int {
  Solution S;
  S.Solve();
  return 0;
}
