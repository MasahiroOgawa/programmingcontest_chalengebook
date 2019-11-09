#include <iostream>
#include <vector>

using namespace std;

int main() {
  // input
  vector<int> a{4, 2, 3, 1, 5};

  // algo
  int n = a.size();
  vector<int> dp(n); //length of LIS which ends of a[i].
  int res{0};

  for (int i = 0; i < n; ++i) {
    dp[i] = 1;
    for (int j = 0; j < i; ++j)
      if (a[j] < a[i])
        dp[i] = max(dp[i], dp[j] + 1);
    res = max(res, dp[i]);
  }

  cout << res << endl;
}
