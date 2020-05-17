#include <algorithm>
#include <iostream>
#include <progchallenge/print.hpp>
#include <vector>

using namespace std;

int main() {
  // param
  static const int n{3};

  // create input
  vector<int> perm(n);
  for (int i = 0; i < n; ++i)
    perm[i] = i;

  // compute permutation and print
  do {
    progchallenge::print(perm);
    cout << endl;
  } while (next_permutation(perm.begin(), perm.end()));

  return 0;
}
