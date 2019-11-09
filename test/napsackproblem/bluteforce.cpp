#include <iostream>

using namespace std;

// input params
int w[] = {2, 1, 3, 2};
int v[] = {3, 2, 4, 2};
int W = 5;
int n = sizeof(w) / sizeof(int);

int maxval(int idx, int lim)
// return max value for extracting from {idx, idx+1, ...} within the limit
// weight of lim.
{
  int res;

  if (idx == n) { // no left goods
    res = 0;
  } else if (lim < w[idx]) { // we cant choose this idx
    res = maxval(idx + 1, lim);
  } else {
    res = max(maxval(idx + 1, lim), maxval(idx + 1, lim - w[idx]) + v[idx]);
  }

  return res;
}

int main() {
  // calc max value
  std::cout << "maximum value = " << maxval(0, W) << '\n';
  return 0;
}
