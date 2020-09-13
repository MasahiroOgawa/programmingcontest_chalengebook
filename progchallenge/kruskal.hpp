#ifndef KRUSKAL_H
#define KRUSKAL_H
#include "adjacencylist.hpp"
#include <vector>

namespace progchallenge {

class Kruskal {
public:
  Kruskal(const int num_vertex, const std::vector<Edge> &edges);
  int comp_mincost();

private:
  int num_vertex_;
  std::vector<Edge> edges_;
};

} // namespace progchallenge

#endif // KRUSKAL_H
