// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
 public:
  auto Solve() -> double;

 private:
  auto Set() -> void;

 private:
  int size;
  vector<int> v;
};

auto Solution::Set() -> void {
  cin >> size;
  v.resize(size);
  for (size_t i = 0; i < v.size(); i++) {
    cin >> v[i];
  }
}

auto Solution::Solve() -> double {
  Set();
  int a = *min_element(v.begin(), v.end());
  int b = *max_element(v.begin(), v.end());
  uint64_t sum = accumulate(v.begin(), v.end(), 0ULL);
  sum -= a;
  sum -= b;
  return (double)sum / (v.size() - 2);
}

auto main() -> int {
  Solution S;
  cout << fixed << setprecision(12) << S.Solve() << '\n';
  return 0;
}
