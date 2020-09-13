#include "kruskal.hpp"
#include "print.hpp"
#include "unionfind_tree.hpp"
#include <algorithm>  // sort
#include <functional> //less
using namespace std;

namespace progchallenge {

Kruskal::Kruskal(const int num_vertex, const std::vector<Edge> &edges)
    : num_vertex_(num_vertex), edges_(edges) {}

int Kruskal::comp_mincost() {
  int res{0};
  sort(edges_.begin(), edges_.end());
  Unionfind_tree uf(num_vertex_);

  for (const auto &edge : edges_) {
    if (!(uf.belong_same(edge.from, edge.to))) {
      uf.unite(edge.from, edge.to);
      res += edge.cost;
    }
  }

  return res;
}

} // namespace progchallenge
