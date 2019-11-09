#include <iostream>
#include <vector>

using namespace std;

// input params
int w[] = {2, 1, 3, 2};
int v[] = {3, 2, 4, 2};
int W = 5;

// other variables
int n = sizeof(w) / sizeof(int);
vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0)); // wee need n+1 because
                                                       // we check in case
                                                       // idx==n, and W+1
                                                       // because we call
                                                       // maxval(0,W).

void printdp() {
  cout << "dp=\n";
  for (auto i : dp) {
    for (auto j : i)
      cout << j << ' ';
    cout << endl;
  }
  cout << endl;
}


int main() {
  for (int idx = 0; idx < n; ++idx) {
    for (int lim = 0; lim <= W; ++lim) {
      if (lim < w[idx]) { // we cant choose this idx's item.
        dp[idx+1][lim] = dp[idx][lim];
      } else {
        dp[idx+1][lim] =
            max(dp[idx][lim], dp[idx][lim - w[idx]] + v[idx]);
      }
    }
  }

  // calc max value
  std::cout << "maximum value = " << dp[n][W] << '\n';
  printdp();

  return 0;
}
