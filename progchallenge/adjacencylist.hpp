#ifndef ADJACENCYLIST_HPP
#define ADJACENCYLIST_HPP

#include <ostream>
#include <vector>

namespace progchallenge {

struct Edge {
  int to;
  int cost;
  int from{0}; // optional. because it can be decided by the vector<Edge> order.
  Edge(const int t, const int c) : to(t), cost(c) {}
  Edge(const int f, const int t, const int c)
      : to(t), cost(c), from(f) {
  } // we want to make this constructor for 3 int inputs
};

inline bool less(const Edge &e1, const Edge &e2) {
  return e1.cost < e2.cost;
} // to avoid multiple definition error, we need inline declaration.

inline bool operator<(const Edge &e1, const Edge &e2) {
  return e1.cost < e2.cost;
}

inline std::ostream &operator<<(std::ostream &os, const Edge &e) {
  return os << e.from << ',' << e.to << ',' << e.cost;
}

using Adjacencylist = std::vector<std::vector<Edge>>;

} // namespace progchallenge
#endif // ADJACENCYLIST_HPP
