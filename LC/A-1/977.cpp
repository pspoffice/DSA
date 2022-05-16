// https://leetcode.com/problems/squares-of-a-sorted-array/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define FAST ios::sync_with_stdio(false), cin.tie(nullptr)

class Solution {
 public:
  auto SortedSquares() -> vector<int>;

  auto Set() -> void;

 private:
  int size = 0;
  vector<int> v;
};

auto Solution::Set() -> void {
  cin >> size;
  v.resize(size);
  for (size_t i = 0; i < v.size(); i++) {
    cin >> v[i];
  }
}

// -20 -15 0 5 10
auto Solution::SortedSquares() -> vector<int> {
  int b = lower_bound(v.begin(), v.end(), 0) - v.begin();
  int a = b - 1;
  int c = 0;
  vector<int> answer(size);
  while (a >= 0 and b < size) {
    if (abs(v[a]) < abs(v[b])) {
      answer[c++] = v[a] * v[a];
      --a;
    } else {
      answer[c++] = v[b] * v[b];
      ++b;
    }
  }
  while (a >= 0) {
    answer[c++] = v[a] * v[a];
    --a;
  }
  while (b < size) {
    answer[c++] = v[b] * v[b];
    ++b;
  }
  return answer;
}

auto main() -> int {
  FAST;
  Solution S;
  S.Set();
  for (const auto& z : S.SortedSquares()) {
    cout << z << ' ';
  }
  cout << endl;
  return 0;
}
