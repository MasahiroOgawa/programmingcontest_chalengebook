#ifndef ADJACENCYLIST_HPP
#define ADJACENCYLIST_HPP

#include <vector>

namespace graph {

struct Edge {
    int to;
    int cost;
    int from{0}; // optional. because it can be decided by the vector<Edge> order.
};

inline bool less(const Edge& e1, const Edge& e2) { return e1.cost < e2.cost; } // to avoid multiple definition error, we need inline declaration.
using Adjacencylist = std::vector<std::vector<Edge> >;

} // namespace graph
#endif // ADJACENCYLIST_HPP
