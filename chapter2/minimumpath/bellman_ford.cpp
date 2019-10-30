#include "../graph/adjacencylist.h"
#include <iostream>

#define DEBUG
using namespace std;

vector<int> bellman_ford(const Adjacencylist &al) {
    // initialize
  static constexpr int INF{999999};
  vector<int> dists(al.size(), INF);
  dists[0] = 0;

  bool update{true};
  while (update) {
    update = false;
    for (size_t vindx = 0; vindx < al.size(); ++vindx) {
      for (auto edge : al[vindx]) {
        if (dists[edge.to] > dists[vindx] + edge.cost) {
          dists[edge.to] = dists[vindx] + edge.cost;
          update = true;
        }
      }

#ifdef DEBUG
      cout << "current-------------\n";
      for (size_t i = 0; i < dists.size(); ++i)
        cout << "d[" << i << "]= " << dists[i] << endl;
#endif

    } // adjacency list
  }   // while

  return dists;
}

bool find_negative_loop(const Adjacencylist &al) {
  vector<int> dists(al.size(), 0);

  for (size_t vindx = 0; vindx < al.size(); ++vindx) {
    for (auto edge : al[vindx]) {
      if (dists[edge.to] > dists[vindx] + edge.cost) {
        dists[edge.to] = dists[vindx] + edge.cost;
        if (vindx == al.size() - 1)
          return true;
      }
    } // edge loop
  }   // vertex loop

  return false;
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

  vector<int> dists = bellman_ford(al);

  cout << "final-------------\n";
  for (size_t i = 0; i < dists.size(); ++i)
    cout << "d[" << i << "]= " << dists[i] << endl;

  cout << "negative loop= " << find_negative_loop(al) << endl;
}
