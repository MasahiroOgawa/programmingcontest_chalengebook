#ifndef UNIONFIND_TREE_HPP
#define UNIONFIND_TREE_HPP

#include <vector>

namespace progchallenge {

class Unionfind_tree {
public:
  Unionfind_tree(int num_elem);
  int find_root(int x);
  void unite(int x, int y);
  bool belong_same(int x, int y) { return find_root(x) == find_root(y); }

private:
  struct Node {
    Node(int par, int ran) : parent(par), rank(ran) {}
    int parent;
    int rank; // number of descendants
  };
  std::vector<Node> nodes;
};

} // namespace progchallenge

#endif // UNIONFIND_TREE_HPP
