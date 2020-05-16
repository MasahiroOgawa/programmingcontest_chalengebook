#include <iostream>
#include <vector>

int minT(const int L, const std::vector<int> &x);
int maxT(const int L, const std::vector<int> &x);

using namespace std;

int main() {
  int L{10};
  vector<int> x{2, 6, 7};

  cout << "min=" << minT(L, x) << ", max=" << maxT(L, x) << endl;

  return 0;
}

int minT(const int L, const std::vector<int> &x) {
  int ans{0};
  for (const auto i : x) {
    ans = std::max(ans, std::min(i, L - i));
  }
  return ans;
}

int maxT(const int L, const std::vector<int> &x) {
  int ans{0};
  for (const auto i : x) {
    ans = std::max(ans, std::max(i, L - i));
  }
  return ans;
}
