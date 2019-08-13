#include <iostream>
#include <vector>

using namespace std;

void printmat(vector<vector<int>> &dp) {
  for (auto i : dp) {
    for (auto j : i)
      cout << ' ' << j;
    cout << endl;
  }
}

int main() {
  // params
  int m = 3;
  vector<int> a = {1, 2, 3};
  int M = 10000;

  // solve
  int n = a.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 0; i <= n; ++i)
    dp[i][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (j - 1 - a[i] >= 0)
        dp[i + 1][j] =
            (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M;
      else
        dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M;
    }
  }

  printmat(dp);
  cout << "answer=" << dp[n][m] << endl;
  return true;
}
