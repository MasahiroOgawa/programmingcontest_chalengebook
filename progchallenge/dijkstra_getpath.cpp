#include "dijkstra.hpp"
#include <algorithm>
#include <iostream>
using namespace std;

namespace progchallenge {

vector<int> get_path(const vector<int> &prev, int t) {
  vector<int> path;
  for (; t != -1; t = prev[t])
    path.push_back(t);
  reverse(path.begin(), path.end());
  return path;
}

///
/// \brief dijkstra
/// \param al
/// \return previous vertices of the minimum path.
/// compute the minimum distance from the first node of input adjacency list
/// using Dijkstra method
std::vector<int> dijkstra_getpath(const Adjacencylist &al) {
  static const int INF{999999};
  vector<int> dists(al.size(), INF);
  vector<bool> used(al.size(), false);
  vector<int> prev(al.size(), -1); // previous vertices of the minimum path.
  dists[0] = 0;

  while (1) {
    // choose minimum distance node as the source of computing the distance
    int sourceidx{-1};
    for (size_t nodeidx = 0; nodeidx < al.size(); ++nodeidx) {
      if (!used[nodeidx] &&
          (sourceidx == -1 || dists[nodeidx] < dists[sourceidx]))
        sourceidx = nodeidx;
    }
    if (sourceidx == -1)
      break;
    used[sourceidx] = true;

    // propagate the distance
    for (auto edge : al[sourceidx])
      if (dists[edge.to] > dists[sourceidx] + edge.cost) {
        dists[edge.to] = dists[sourceidx] + edge.cost;
        prev[edge.to] = sourceidx;
      }
  } // while

  // compute minimum path
  vector<int> minpath = get_path(prev, al.size() - 1);

  return minpath;
}

} // namespace progchallenge
