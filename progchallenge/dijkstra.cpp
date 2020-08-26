#include "dijkstra.hpp"
#include "adjacencylist.hpp"
#include <iostream>
using namespace std;

namespace progchallenge {

///
/// \brief dijkstra
/// \param al
/// \return the minimum distance from the first node of input adjacency list
/// using Dijkstra method
///
std::vector<int> dijkstra(const Adjacencylist &al) {
  static const int INF{999999};
  vector<int> dists(al.size(), INF);
  vector<bool> used(al.size(), false);
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
      dists[edge.to] = min(dists[edge.to], dists[sourceidx] + edge.cost);

    //    // print distances
    //    cout << "current-------------\n";
    //    for (size_t i = 0; i < dists.size(); ++i)
    //      cout << "d[" << i << "]= " << dists[i] << endl;
  } // while

  return dists;
}

} // namespace progchallenge
