// https://leetcode.com/problems/merge-sorted-array/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define FAST std::ios::sync_with_stdio(false), std::cin.tie(nullptr)

class Solution {
 public:
  auto Set() -> void {
    std::string s, x;
    std::getline(std::cin, s);
    std::istringstream p(s);
    while (p >> x) {
      a.push_back(stoi(x));
    }
    std::getline(std::cin >> std::ws, s);
    std::istringstream q(s);
    while (q >> x) {
      b.push_back(stoi(x));
    }
  }

  auto Solve() -> std::vector<int> {
    int p = a.size() - 1;
    int q = b.size() - 1;
    int i = a.size() + b.size() - 1;
    a.resize(a.size() + b.size());
    while (p >= 0 and q >= 0) {
      if (a[p] > b[q]) {
        a[i] = a[p--];
      } else {
        a[i] = b[q--];
      }
      i--;
    }
    while (i and q >= 0) {
      a[i--] = b[q--];
    }
    return a;
  }

 private:
  int size = 0;
  std::vector<int> a, b;
};

auto main() -> int {
  FAST;
  Solution S;
  S.Set();
  for (const auto& z : S.Solve()) {
    std::cout << z << ' ';
  }
  std::cout << std::endl;
  return 0;
}
