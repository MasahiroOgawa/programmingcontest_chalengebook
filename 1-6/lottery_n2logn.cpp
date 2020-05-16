#include <algorithm> // for sort()
#include <iostream>
#include <progchallenge/search.hpp>
#include <vector>

bool exist_exactsum(std::vector<int> &nums, const int sum);

using namespace std;

int main() {
  // inputs
  vector<int> k{1, 3, 5};
  //  int m{10};
  int m{9};

  // result
  if (exist_exactsum(k, m))
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}

bool exist_exactsum(std::vector<int> &nums, const int sum) {
  const int n = nums.size();

  // list all possible nums[k]+nums[l]
  std::vector<int> numskl;
  for (int k = 0; k < n; ++k) {
    for (int l = 0; l < n; ++l) {
      numskl.push_back(nums[k] + nums[l]);
    }
  }

  std::sort(numskl.begin(), numskl.end()); // for binary search

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (progchallenge::binary_search(sum - nums[i] - nums[j], numskl))
        return true;
    }
  }

  return false;
}
