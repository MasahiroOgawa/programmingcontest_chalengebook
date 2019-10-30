#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <vector>

struct Edge {
  int to;
  int cost;
};

bool less(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; }
using Adjacencylist = std::vector<std::vector<Edge>>;

#endif // ADJACENCYLIST_H
