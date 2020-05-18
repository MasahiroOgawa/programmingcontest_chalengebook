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
       vector<int>(W + 1, 0)); // wee need n+1 because we check in case idx==n,
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

int main() {
  for (int idx = 0; idx < n; ++idx) {
    for (int lim = 0; lim <= W; ++lim) {
      dp[idx + 1][lim] = max(dp[idx + 1][lim], dp[idx][lim]); // send value down
      if (lim + w[idx] <= W) {
        dp[idx + 1][lim + w[idx]] =
            max(dp[idx + 1][lim + w[idx]],
                dp[idx][lim] + v[idx]); // send value diagonal
      }
    }
  }

  // calc max value
  std::cout << "maximum value = " << dp[n][W] << '\n';
  printdp();

  return 0;
}
