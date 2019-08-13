#include "binarysearchtree.h"
#include <vector>
using namespace std;

int main() {
  Binarysearchtree bt;
  vector<int> input{7, 2, 15, 1, 5, 4, 10, 17, 8, 11, 16, 19};
  for (auto i : input)
    bt.insert(i);
  bt.print();
}
