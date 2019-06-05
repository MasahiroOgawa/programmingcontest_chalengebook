#include <iostream>
#include <vector>
using namespace std;

void printdp(vector<vector<int>> &v) {
  cout << "dp=\n";
  for (auto &vv : v) {
    for (auto i : vv)
      cout << i << ' ';
    cout << endl;
  }
}

int lcp(string &s, string &t) {
  int n = s.size();
  int m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i] == t[j])
        dp[i + 1][j + 1] = dp[i][j] + 1;
      else
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
    }
  }
  printdp(dp);

  return dp[n][m];
}

int main() {
  // params
  string s{"abcd"};
  string t{"becd"};

  cout << "answer = " << lcp(s, t) << endl;
}
