#ifndef DJIKSTRA_HPP
#define DJIKSTRA_HPP

#include "adjacencylist.hpp"

namespace progchallenge {

std::vector<int> dijkstra(const Adjacencylist &al);
std::vector<int> dijkstra_heap(const Adjacencylist &al);

} // namespace progchallenge
#endif // DJIKSTRA_HPP
