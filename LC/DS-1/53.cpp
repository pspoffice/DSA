// https://leetcode.com/problems/maximum-subarray/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  auto Solve() -> int;

 private:
  auto Set() -> void;
  auto Print() -> void;

 private:
  int size;
  vector<int> a, b;
};

auto Solution::Print() -> void {
  for (size_t i = 0; i < b.size(); i++) {
    cout << b[i] << ' ';
  }
  cout << '\n';
}

auto Solution::Set() -> void {
  cin >> size;
  a.resize(size);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
}

auto Solution::Solve() -> int {
  Set();
  b.resize(a.size());
  b[0] = a[0];
  for (size_t i = 1; i < a.size(); i++) {
    b[i] = max(a[i], a[i] + b[i - 1]);
  }
  const int answer = *max_element(b.begin(), b.end());
  return answer;
}

auto main() -> int {
  Solution S;
  cout << S.Solve() << '\n';
  return 0;
}
