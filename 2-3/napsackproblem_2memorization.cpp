#include <iostream>
#include <vector>

using namespace std;

// input params
vector<int> w{2, 1, 3, 2};
vector<int> v{3, 2, 4, 2};
int W = 5;

// other variables
int n = w.size();
vector<vector<int>>
    dp(n + 1,
       vector<int>(W + 1, -1)); // wee need n+1 because we check in case idx==n,
                                // and W+1 because we call maxval(0,W).

void printdp() {
  cout << "dp=\n";
  for (auto i : dp) {
    for (auto j : i)
      cout << j << ' ';
    cout << endl;
  }
  cout << endl;
}

int maxval(int idx, int lim)
// return max value for extracting from {idx, idx+1, ...} within the limit
// weight of lim.
{
  // reuse if it is already computed
  if (dp[idx][lim] >= 0)
    return dp[idx][lim];

  int res;

  if (idx == n) { // no left goods
    res = 0;
  } else if (lim < w[idx]) { // we cant choose this idx
    res = maxval(idx + 1, lim);
  } else {
    res = max(maxval(idx + 1, lim), maxval(idx + 1, lim - w[idx]) + v[idx]);
  }

  return dp[idx][lim] = res;
}

int main() {
  // calc max value
  std::cout << "maximum value = " << maxval(0, W) << '\n';

  // note: this will compute only neccessary velues.
  printdp();

  return 0;
}
