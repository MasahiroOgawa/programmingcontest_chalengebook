#ifndef WARSHALL_FLOYD_HPP
#define WARSHALL_FLOYD_HPP

#include "adjacencylist.hpp"

namespace progchallenge {

  std::vector<std::vector<int>> warshall_floyd(const Adjacencylist &al);

} // namespace progchallenge
#endif // WARSHALL_FLOYD_HPP
