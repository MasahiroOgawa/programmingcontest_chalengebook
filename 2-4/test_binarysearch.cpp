#include "binarysearchtree.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {
  Binarysearchtree bt;
  vector<int> input{7, 2, 15, 1, 5, 4, 10, 17, 8, 11, 16, 19};

  if (bt.find(11))
    cout << "11 exists.\n";
  else
    cout << "11 doesnt exist.\n";

  for (auto i : input)
    bt.insert(i);
  bt.print();
}
