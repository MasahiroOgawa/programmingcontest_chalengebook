#include <iostream>
#include <vector>
#include <climits>

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
  int n = a.size();
  vector<int> dp(n, INT_MAX);

  for (int i = 0; i < n; ++i) {
      *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
  }

  print_vec(dp);
  vector<int>::iterator pos = lower_bound(dp.begin(), dp.end(), INT_MAX);
  cout << "longest increasing subsequence = " << distance(dp.begin(), pos) << endl;
}
