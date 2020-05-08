#include <complex>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // param
  static constexpr int cash{750000};
  static constexpr int num_round{2};
  static constexpr double win_prob{0.75};

  // def
  static constexpr int num_bin = 1 << num_round;
  // the above is the same with this.
  //  static constexpr int num_bin = std::pow(2,num_round);
  vector<double> prev(num_bin + 1, 0); // probability of getting money for each bin. previous round.
  vector<double> next(num_bin + 1, 0);
  prev[num_bin] = 1; // in case originally has over 1M dollar.

  // compute by dynamic programming
  for (int r = 0; r < num_round; ++r) {
    for (int i = 0; i <= num_bin; ++i) {
      int jub = min(i, num_bin - i);
      double prob_get = 0.0;
      for (int j = 0; j <= jub; ++j)
        prob_get = max(prob_get,
                       win_prob * prev[i + j] + (1 - win_prob) * prev[i - j]);
      next[i] = prob_get;
    }
    swap(prev, next);
  }

  int bin_idx = cash * num_bin / 1000000;
  cout << "win probablility=" << prev[bin_idx] << endl;

  return 0;
}
