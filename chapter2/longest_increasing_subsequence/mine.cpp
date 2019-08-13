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
  int n = a.size();
  vector<int> dp;

  dp.push_back(a[0]);

  if (a[1] < dp.at(0))
    dp.at(0) = a[1];
  else
    dp.push_back(a[1]);

  for (int i = 2; i < n; ++i) {
    if (a[i] == dp.back())
      continue;
    else if (a[i] < dp.back()) {
      if (a[i] > dp.end()[-2])
        dp.back() = a[i];
    } else
      dp.push_back(a[i]);
  }

  print_vec(dp);
  cout << "longest increasing subsequence = " << dp.size() << endl;
}
