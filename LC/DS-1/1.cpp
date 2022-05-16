// https://leetcode.com/problems/two-sum/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(nullptr)

class Solution {
 public:
  auto TwoSum() const -> vector<int>;

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

auto Solution::TwoSum() const -> vector<int> {
  unordered_map<int, int> w;
  w.reserve(size);
  for (int i = 0; i < size; i++) {
    const int r = x - v[i];
    if (w.count(r)) {
      return {i, w[r]};
    } else {
      w[v[i]] = i;
    }
  }
  return {-1, -1};
}

auto main() -> int {
  FAST;
  Solution S;
  S.Set();
  for (const auto& z : S.TwoSum()) {
    cout << z << ' ';
  }
  cout << '\n';
  return 0;
}
