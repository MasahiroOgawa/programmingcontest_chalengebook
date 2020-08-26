#include "../graph/adjacencylist.h"
#include <iostream>
using namespace std;

void warshall_floyd(const Adjacencylist &al) {
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

  // print result
  for (size_t i = 0; i < dists.size(); ++i)
    for (size_t j = 0; j < dists[i].size(); ++j)
      cout << "d[" << i << "][" << j << "]=" << dists[i][j] << endl;
}

int main() {

  vector<Edge> a{{1, 2}, {2, 5}};
  vector<Edge> b{{0, 2}, {2, 4}, {3, 6}, {4, 10}};
  vector<Edge> c{{0, 5}, {1, 4}, {3, 2}};
  vector<Edge> d{{1, 6}, {2, 2}, {5, 1}};
  vector<Edge> e{{1, 10}, {5, 3}, {6, 5}};
  vector<Edge> f{{3, 1}, {4, 3}, {6, 9}};
  vector<Edge> g{{4, 5}, {5, 9}};
  Adjacencylist al({a, b, c, d, e, f, g});

  warshall_floyd(al);
}
