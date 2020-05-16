#include <algorithm>
#include <iostream>
#include <vector>

int max_perimeter(const std::vector<int> &sidelength);

using namespace std;

int main() {
  // inputs
  //    vector<int> a{2, 3, 4, 5, 10};
  vector<int> a{4, 5, 10, 20};

  // compute
  int ans = max_perimeter(a);

  // result
  cout << ans << endl;
  return 0;
}

int max_perimeter(const std::vector<int> &sidelength) {
  int maxperim{0};
  const int n = sidelength.size();

  // select sides as i<j<k not to select the same one.
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        int perim = sidelength[i] + sidelength[j] + sidelength[k];
        int maxlen = std::max({sidelength[i], sidelength[j], sidelength[k]});
        int rest = perim - maxlen;
        if (maxlen < rest)
          maxperim = perim;
      }
    }
  }

  return maxperim;
}
