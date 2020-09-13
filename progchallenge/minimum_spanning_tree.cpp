#include "minimum_spanning_tree.hpp"
#include <limits>

using namespace std;

namespace progchallenge {

int prim(const Adjacencymat &am) {
  // define variables
  int V = am.size();
  vector<int> mincost(
      V,
      numeric_limits<int>::max()); // minimum cost in X. note:
                                   // numeric_limits<int>::infinity() returns 0.
  mincost[0] = 0;
  vector<bool> used(V, false);
  int res{0};

  while (true) {
    int v = -1; // node which exists outside X and has min cost from X
    for (int u = 0; u < V; ++u)
      if (!used[u] && (v == -1 || mincost[u] < mincost[v]))
        v = u;
    if (v == -1)
      break;

    used[v] = true;
    res += mincost[v];

    for (int u = 0; u < V; ++u)
      mincost[u] = min(mincost[u], am[v][u]);
  }

  return res;
}

} // namespace progchallenge
