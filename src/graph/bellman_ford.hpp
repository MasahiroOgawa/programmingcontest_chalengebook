#ifndef BELLMAN_FORD_HPP
#define BELLMAN_FORD_HPP

#include "adjacencylist.hpp"

namespace graph {

static constexpr int INF{ 999999 };

std::vector<int> bellman_ford(const Adjacencylist& al);
bool find_negative_loop(const Adjacencylist& al);

} // namespace graph
#endif // BELLMAN_FORD_HPP
