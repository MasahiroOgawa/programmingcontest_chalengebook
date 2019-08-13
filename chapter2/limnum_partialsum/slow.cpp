#include <iostream>
#include <string>

using namespace std;

//--------------
// return true if we can create sum(a[i]) = K | num of a[i] = m[i].
//--------------

int main() {
  // input
  int a[] = {3, 5, 8};
  int m[] = {3, 2, 2};
  int K = 17;

  // solve
  int n = sizeof(a) / sizeof(int);
  bool dp[n + 1][K + 1];

  dp[0][0] = true;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= K; ++j)
      for (int k = 0; k < +m[i] && k * a[i] <= j; ++k)
        dp[i + 1][j] = dp[i][j - k * a[i]];

  string ans = dp[n][K] ? "yes" : "no";
  cout << ans << endl;

  return 0;
}
