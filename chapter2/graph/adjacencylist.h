#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <vector>

struct Edge {
  int to;
  int cost;
};

using Adjacencylist = std::vector<std::vector<Edge>>;

#endif // ADJACENCYLIST_H
