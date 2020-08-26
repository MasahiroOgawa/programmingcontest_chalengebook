#include "../../src/graph/adjacencylist.h"
#include <iostream>
#include <queue>
using namespace std;

///
/// \brief dijkstra
/// \param al
/// compute the minimum distance from the first node of input adjacency list
/// using Dijkstra method using heap
void dijkstra_heap(const Adjacencylist &al) {
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

    // print distances
    cout << "current-------------\n";
    for (size_t i = 0; i < dists.size(); ++i)
      cout << "d[" << i << "]= " << dists[i] << endl;
  } // while
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

  dijkstra_heap(al);
}
