// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  auto Solve() -> bool;

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

auto Solution::Solve() -> bool {
  Set();
  unordered_map<int, int> a;
  for (size_t i = 0; i < v.size(); i++) {
    const int x = v[i];
    if (a[x]) {
      return 1;
    }
    a[x] = 1;
  }
  return 0;
}

auto main() -> int {
  Solution S;
  cout << S.Solve() << '\n';
  return 0;
}
