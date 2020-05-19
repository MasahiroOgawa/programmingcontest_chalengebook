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
  //    vector<int> a{4, 2, 3, 1, 5};
  vector<int> a{4, 3, 5, 1, 2, 3, 6};

  // algo
  vector<int> dp{a[0]};

  for (size_t i = 1; i < a.size(); ++i) {
    if (a[i] == dp.back())
      // ignore
      continue;
    else if (a[i] < dp.back()) {
      // this part is wrong.
      if (a[i] > dp.end()[-2])
        // swap
        dp.back() = a[i];
    } else
      // add
      dp.push_back(a[i]);
  }

  // result
  print_vec(dp);
  cout << "longest increasing subsequence = " << dp.size() << endl;
}
