#include "unionfind_tree.hpp"
using namespace std;

namespace progchallenge {

Unionfind_tree::Unionfind_tree(int num_elem) {
  for (int i = 0; i < num_elem; ++i) {
    nodes.push_back(Node(i, 0));
  }
}

int Unionfind_tree::find_root(int x) {
  if (nodes[x].parent == x)
    return x;
  else
    return nodes[x].parent = find_root(nodes[x].parent);
}

void Unionfind_tree::unite(int x, int y) {
  x = find_root(x);
  y = find_root(y);

  if (x == y)
    return;
  else if (nodes[x].rank < nodes[y].rank)
    nodes[x].parent = y;
  else {
    nodes[y].parent = x;
    if (nodes[x].rank == nodes[y].rank)
      nodes[x].rank++;
  }
}

} // namespace progchallenge
