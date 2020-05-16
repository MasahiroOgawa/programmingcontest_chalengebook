#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// judge whether we can sum to k using int a1,...,an

// input
vector<int> a{1, 2, 4, 7};
// int target_sum = 13;
int target_sum = 15;

// use a1,...,ai and compute sum, and judge sum==k or not.
bool depth_first_search(unsigned int i, int sum) {
  if (i == a.size())
    return sum == target_sum;
  assert(i < a.size());

  if (depth_first_search(i + 1, sum))
    return true;
  if (depth_first_search(i + 1, sum + a[i]))
    return true;

  return false;
}

int main() {
  if (depth_first_search(0, 0))
    cout << "Yes\n";
  else
    cout << "No\n";
}
