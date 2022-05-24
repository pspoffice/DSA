// https://leetcode.com/problems/intersection-of-two-arrays-ii/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(nullptr)

class Solution {
 public:
  Solution();

  auto Solve() -> vector<int>;

 private:
  int size = 0;
  vector<int> a, b;
};

Solution::Solution() {
  cin >> size;
  a.resize(size), b.resize(size);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  for (size_t i = 0; i < b.size(); i++) {
    cin >> b[i];
  }
}

auto Solution::Solve() -> vector<int> {
  unordered_map<int, int> p;
  for (const auto x : a) {
    p[x]++;
  }
  vector<int> c;
  for (const auto x : b) {
    if (p[x]-- > 0) {
      c.push_back(x);
    }
  }
  return c;
}

auto main() -> int {
  FAST;
  Solution S;
  for (const auto x : S.Solve()) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
