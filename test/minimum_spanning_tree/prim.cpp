#include <iostream>
#include <vector>
using namespace std;

using Adjacencymat = vector<vector<int>>;
static const int INF{1000000};

int prim(const Adjacencymat &am) {
  // define variables
  int V = am.size();
  vector<int> mincost(V, INF); // minimum cost in X
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

int main() {
  Adjacencymat am{
      {0, INF, 1, INF, INF, INF, INF}, {INF, 0, 2, INF, 10, INF, INF},
      {1, 2, 0, 3, INF, 7, INF},       {INF, INF, 3, 0, INF, 1, 5},
      {INF, 10, INF, INF, 0, 5, INF},  {INF, INF, 7, 1, 5, 0, 8},
      {INF, INF, INF, 5, INF, 8, 0}};

  cout << "minimum spanning tree's total cost = " << prim(am) << endl;
}
