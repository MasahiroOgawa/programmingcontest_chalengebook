#include "warshall_floyd.hpp"
#include <iostream>
using namespace std;

namespace progchallenge {

std::vector<std::vector<int>> warshall_floyd(const Adjacencylist &al) {
  // init distances
  static const int INF{999999};
  vector<vector<int>> dists(al.size(), vector<int>(al.size(), INF));
  for (size_t i = 0; i < al.size(); ++i)
    dists[i][i] = 0;
  for (size_t i = 0; i < al.size(); ++i)
    for (size_t j = 0; j < al[i].size(); ++j)
      dists[i][al[i][j].to] = al[i][j].cost;

  // main algo
  for (size_t k = 0; k < al.size(); ++k)
    for (size_t i = 0; i < al.size(); ++i)
      for (size_t j = 0; j < al.size(); ++j)
        dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);

  return dists;
}

} // namespace progchallenge
