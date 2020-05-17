#include <algorithm> // sort
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // input params
  static const int range{10};
  static vector<int> points{1, 7, 15, 20, 30, 50};

  // prepare computation
  int n = points.size();
  sort(points.begin(), points.end());
  vector<int> checked_pts; // for output

  // compute min check points
  for (int i = 0; i < n;) {
    int leftmost_pt = points[i]; // non covered left most point

    // define a check point p; distance range from leftmost_pt
    while (i < n && points[i] <= leftmost_pt + range)
      ++i;
    int p = points[i - 1];
    checked_pts.push_back(p);

    // set next non covered left most point
    while (i < n && points[i] <= p + range)
      ++i;
  }

  // print the answer
  cout << "checked poits = {";
  for (auto i : checked_pts)
    cout << i << ' ';
  cout << "}\n";
  cout << "min number of checked points = " << checked_pts.size() << endl;

  return 0;
}
