#include "unionfind_tree.h"
#include <iostream>
using namespace std;

struct Info {
  unsigned int t; // 1,2
  unsigned int x; // 1,2,...,num_animals
  unsigned int y;
};

int main() {
  // input
  unsigned int num_animals = 100;
  vector<Info> infos{{1, 101, 1}, {2, 1, 2}, {2, 2, 3}, {2, 3, 3},
                     {1, 1, 3},   {2, 3, 1}, {1, 5, 5}};

  cout << "info are: \n";
  for (auto i : infos) {
    cout << i.t << ' ' << i.x << ' ' << i.y << endl;
  }

  // algo
  unsigned num_wrong{0};
  Unionfid_tree ut(3 * num_animals); // correspondense are x:x-A, x+num_animals:
                                     // x-B, x+2*num_animals: x-C

  int num_info{0};
  for (auto i : infos) {
    ++num_info;
    if (i.x <= 0 || i.x > num_animals || i.y <= 0 || i.y > num_animals) {
      cout << "info " << num_info << " is wrong.\n";
      ++num_wrong;
      continue;
    }

    if (i.t == 1) {
      if (ut.same(i.x, i.y + num_animals) ||
          ut.same(i.x, i.y + 2 * num_animals)) {
        cout << "info " << num_info << " is wrong.\n";
        ++num_wrong;
      } else {
        ut.unite(i.x, i.y);
        ut.unite(i.x + num_animals, i.y + num_animals);
        ut.unite(i.x + 2 * num_animals, i.y + 2 * num_animals);
      }
    } else if (i.t == 2) {
      if (ut.same(i.x, i.y) || ut.same(i.x, i.y + 2 * num_animals)) {
        cout << "info " << num_info << " is wrong.\n";
        ++num_wrong;
      } else {
        ut.unite(i.x, i.y + num_animals);
        ut.unite(i.x + num_animals, i.y + 2 * num_animals);
        ut.unite(i.x + 2 * num_animals, i.y);
      }
    } else {
      cout << "info " << num_info << " is wrong.\n";
      ++num_wrong;
    }
  }

  cout << "number of wrong info = " << num_wrong << endl;
  return 0;
}
