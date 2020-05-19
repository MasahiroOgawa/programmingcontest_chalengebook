#include <iostream>
#include <vector>

using namespace std;

void printdp(vector<int> &dp) {
  cout << "dp=";
  for (auto i : dp)
    cout << i << ' ';
  cout << endl;
}

int main() {
  // input
  vector<int> w = {3, 4, 2}; // weight
  vector<int> v = {4, 5, 3}; // value
  int W = 7;

  // define values
  int n = w.size();
  vector<int> dp(W + 1, 0);

  // solve
  for (int i = 0; i < n; ++i)
    // note: loop should be forward to use updated value.
    for (int j = w[i]; j <= W; ++j)
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

  printdp(dp);

  cout << "answer = " << dp[W] << endl;
  return 0;
}
