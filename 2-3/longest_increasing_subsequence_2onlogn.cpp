#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> &dp) {
  cout << "dp =";
  for (auto i : dp)
    cout << ' ' << i;
  cout << endl;
}

int main() {
  // input
  vector<int> a{4, 2, 3, 1, 5};

  // algo
  int inf{INT_MAX};
  vector<int> dp(a.size(), inf);

  for (size_t i = 0; i < a.size(); ++i) {
    *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
  }

  // result
  print_vec(dp);
  cout << "longest increasing subsequence = "
       << distance(dp.begin(), lower_bound(dp.begin(), dp.end(), inf)) << endl;
  //  cout << "longest increasing subsequence = "
  //       << lower_bound(dp.begin(), dp.end(), INT_MAX) - dp.begin() << endl;
}
