#ifndef BELLMAN_FORD_HPP
#define BELLMAN_FORD_HPP

#include "adjacencylist.hpp"

std::vector<int> bellman_ford(const Adjacencylist& al);
bool find_negative_loop(const Adjacencylist& al);

#endif // BELLMAN_FORD_HPP
