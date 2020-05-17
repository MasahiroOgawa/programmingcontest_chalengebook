#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  // input params
  vector<int> s{1, 2, 4, 6, 8};
  vector<int> e{3, 5, 7, 9, 10};

  // init jobs
  map<int, int> jobs;
  for (size_t i = 0; i < s.size(); ++i)
    jobs.insert(make_pair(e[i], s[i]));
  for (auto j : jobs)
    cout << j.first << ',' << j.second << endl;

  // find jobs
  int current_time{0};
  int ans{0};
  for (auto j : jobs) {
    if (current_time < j.second) {
      // take the job j.
      ++ans;
      current_time = j.first;
    }
  }

  cout << "max number of jobs = " << ans << endl;
  return 0;
}
