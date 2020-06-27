#include <iostream>
#include <vector>

using namespace std;

void printmat(vector<vector<int>>& dp){
    for(auto i : dp){
        for(auto j : i)
            cout << j << ' ';
        cout << endl;
    }
}

int main() {
  // input
  int n = 4;
  int m = 3;
  int M = 10000;

  // solve
  vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j <= n; ++j) {
        if(j >= i)
            dp[i][j] = dp[i-1][j] + dp[i][j-i];
        else
            dp[i][j] = dp[i-1][j];
    }
  }

  printmat(dp);
  cout << "ans = " << dp[m][n] % M << endl;

  return 0;
}
