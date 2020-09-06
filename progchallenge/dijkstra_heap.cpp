#include "dijkstra.hpp"
#include <iostream>
#include <queue>
using namespace std;

namespace progchallenge {

///
/// \brief dijkstra_heap
/// \return distances
/// \param al
/// compute the minimum distance from the first node of input adjacency list
/// using Dijkstra method using heap
std::vector<int> dijkstra_heap(const Adjacencylist &al) {
  static const int INF{999999};
  vector<int> dists(al.size(), INF);
  dists[0] = 0;
  using P = pair<int, int>; // <minimum distance, vertex index>
  priority_queue<P, vector<P>, greater<P>> que; // use heap!
  que.push(P(0, 0));

  while (!que.empty()) {
    // choose minimum distance node as the source of computing the distance
    P minnode = que.top();
    que.pop();
    int sourceidx = minnode.second;
    if (dists[sourceidx] < minnode.first)
      continue;

    // propagate the distance
    for (auto edge : al[sourceidx]) {
      if (dists[edge.to] > dists[sourceidx] + edge.cost) {
        dists[edge.to] = dists[sourceidx] + edge.cost;
        que.push(P(dists[edge.to], edge.to));
      }
    }
  } // while

  return dists;
}

} // namespace progchallenge
