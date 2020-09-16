#include <iostream>
#include <progchallenge/adjacencylist.hpp>
#include <queue>
using namespace std;
using namespace progchallenge;

///
/// \brief dijkstra_heap
/// \param al
/// compute 1st, and 2nd shortest path
void dijkstra_heap(const progchallenge::Adjacencylist &al) {
  static const int INF{999999};
  vector<int> dists(al.size(), INF);
  vector<int> dists2(al.size(), INF);
  dists[0] = 0;
  using P = pair<int, int>; // <minimum distance, vertex index>
  priority_queue<P, vector<P>, greater<P>> que; // use heap!
  que.push(P(0, 0));

  while (!que.empty()) {
    // choose minimum distance node as the source of computing the distance
    P minnode = que.top();
    que.pop();
    int sourceidx = minnode.second;
    if (dists2[sourceidx] < minnode.first)
      continue;

    // propagate the distance
    for (auto edge : al[sourceidx]) {
      // update dist
      int new_d = dists[sourceidx] + edge.cost;
      if (dists[edge.to] > new_d) {
        swap(dists[edge.to], new_d);
        que.push(P(dists[edge.to], edge.to));
      }

      // choose smaller cost within round trip or new_d distance.
      int round_d = dists[sourceidx] + 3 * edge.cost;
      int candity = min(new_d, round_d);

      // update dist2
      if (dists2[edge.to] > candity && dists[edge.to] < candity) {
        dists2[edge.to] = candity;
        que.push(P(dists2[edge.to], edge.to));
      }
    }

    // print distances
    cout << "current-------------\n";
    for (size_t i = 0; i < dists.size(); ++i) {
      cout << "d[" << i << "]= " << dists[i] << endl;
      cout << "d2[" << i << "]= " << dists2[i] << endl;
    }
  } // while
}

int main() {
  // define undirected adjacency list
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
