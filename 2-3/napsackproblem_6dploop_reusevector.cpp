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
  vector<int> w = {2, 1, 3, 2}; // weight
  vector<int> v = {3, 2, 4, 2}; // value
  int W = 5;                    // limit weight

  // define values
  int n = w.size();
  vector<int> dp(W + 1, 0);

  // solve
  for (int i = 0; i < n; ++i)
    // note: loop should be backward to get previous value.
    for (int j = W; j >= w[i]; --j)
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

  printdp(dp);

  cout << "answer = " << dp[W] << endl;
  return 0;
}
