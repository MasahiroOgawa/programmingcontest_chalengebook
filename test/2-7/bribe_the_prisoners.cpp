#include <iostream>
#include <vector>
using namespace std;

std::ostream &operator<<(std::ostream &os, const std::vector<int> &v) {
  for (auto &i : v)
    os << i << ' ';
  return os;
}

std::ostream &operator<<(std::ostream &os,
                         const std::vector<std::vector<int>> &v) {
  for (auto &i : v)
    os << i << '\n';
  return os;
}

int bribe(const int num_prisoners, const std::vector<int> &freed_prisoners) {
  int num_freed = freed_prisoners.size();
  // dp[i][j] = minimum number of coins which needs to free all the prisoners
  // within (freed_prisoners[i],freed_prisoners[j]), which will be computed by
  // dynamic programming.
  vector<vector<int>> dp(num_freed + 1, vector<int>(num_freed + 2, 0));
  vector<int> A{0}; // A = {0, freed_prisoners, num_prisoners+1}.
  A.insert(A.end(), freed_prisoners.begin(), freed_prisoners.end());
  A.push_back(num_prisoners + 1);

  // fill dp. we need small segment result first to compute big segment result
  // like dp[0][num_freed].
  for (int w = 2; w < num_freed + 2; ++w) {
    // w = index gap to be freed prisoners.
    for (int i = 0; i < num_freed + 2 - w; ++i) {
      int j = i + w;

      // compute minimum cost after free A[k].
      int cost = dp[i + 1][j];
      for (int k = i + 2; k < j; ++k) {
        cost = min(cost, dp[i][k] + dp[k][j]);
      }

      dp[i][j] = cost + A[j] - A[i] - 2;
    }
  }

  cout << "dp = \n" << dp << endl;
  return dp[0][num_freed + 1];
}

int main() {
  int num_prisoners{20};
  vector<int> freed_prisoners{3, 6, 14};

  cout << "answer = " << bribe(num_prisoners, freed_prisoners) << endl;
  return 0;
}
