#include "../graph/adjacencylist.h"
#include <algorithm>
#include <iostream>
using namespace std;


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
/// compute the minimum distance from the first node of input adjacency list
/// using Dijkstra method
void dijkstra(const Adjacencylist &al) {
  static const int INF{999999};
  vector<int> dists(al.size(), INF);
  vector<bool> used(al.size(), false);
  vector<int> prev(al.size(), -1);
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

    // print distances
    cout << "current-------------\n";
    for (size_t i = 0; i < dists.size(); ++i)
      cout << "d[" << i << "]= " << dists[i] << endl;
  } // while

  // print minimum path
  vector<int> minpath = get_path(prev, al.size()-1);
  cout << "minimam path: ";
  for (const auto i : minpath)
    cout << i << ' ';
  cout << endl;
}


int main() {
  // define adjacency list
  vector<Edge> a{{1, 2}, {2, 5}};
  vector<Edge> b{{0, 2}, {2, 4}, {3, 6}, {4, 10}};
  vector<Edge> c{{0, 5}, {1, 4}, {3, 2}};
  vector<Edge> d{{1, 6}, {2, 2}, {5, 1}};
  vector<Edge> e{{1, 10}, {5, 3}, {6, 5}};
  vector<Edge> f{{3, 1}, {4, 3}, {6, 9}};
  vector<Edge> g{{4, 5}, {5, 9}};
  Adjacencylist al({a, b, c, d, e, f, g});

  dijkstra(al);
}
