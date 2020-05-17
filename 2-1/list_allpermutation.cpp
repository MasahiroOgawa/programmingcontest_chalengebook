#include <iostream>
#include <progchallenge/print.hpp>
#include <vector>
using namespace std;

// we need these global variables because we use a recursive function.
static const int n{4};
vector<bool> used(n, false);
vector<int> perm(n);

///
/// \brief create_print_sortperm
/// \param pos
///
void create_print_sortperm(const int pos) {
  if (pos == n) {
    progchallenge::print(perm);
    cout << endl;
  }

  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      perm[pos] = i;
      used[i] = true;
      create_print_sortperm(pos + 1);
      used[i] = false;
    }
  }

  return;
}

///
/// \brief main
/// \return
///
int main() {
  create_print_sortperm(0);

  return 0;
}
