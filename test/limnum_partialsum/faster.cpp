#include <iostream>
#include <vector>

using namespace std;

//--------------
// return the left number for creating sum(a[i]) = K | num of a[i] = m[i].
//--------------

void print_dp(vector<int> dp){
    cout << "dp=";
    for(auto i : dp) cout << ' ' << i;
    cout << endl;
}

int main() {
  // input
  int a[] = {3, 5, 8};
  int m[] = {3, 2, 2};
  int K = 17;

  // solve
  int n = sizeof(a) / sizeof(int);
  vector<int> dp(K + 1, -1);

  dp[0] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j <= K; ++j)
      if (dp[j] >= 0)
        dp[j] = m[i];
      else if (j < a[i] || dp[j - a[i]] <= 0)
        dp[j] = -1;
      else
        dp[j] = dp[j - a[i]] - 1;

  print_dp(dp);

  string ans = dp[K] >= 0 ? "yes" : "no";
  cout << ans << endl;

  return 0;
}
