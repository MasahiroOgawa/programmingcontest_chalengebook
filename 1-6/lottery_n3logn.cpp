#include <algorithm> // for sort()
#include <iostream>
#include <progchallenge/search.hpp>
#include <vector>

bool exist_exactsum(std::vector<int> &nums, const int sum);

using namespace std;

int main() {
  // inputs
  vector<int> k{1, 3, 5};
  int m{10};
  //  int m{9};

  // result
  if (exist_exactsum(k, m))
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}

bool exist_exactsum(std::vector<int> &nums, const int sum) {
  std::sort(nums.begin(), nums.end()); // for binary search
  const int n = nums.size();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        if (progchallenge::binary_search(sum - nums[i] - nums[j] - nums[k],
                                         nums))
          return true;
      }
    }
  }

  return false;
}
