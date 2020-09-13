#ifndef MINIMUM_SPANNING_TREE_HPP
#define MINIMUM_SPANNING_TREE_HPP
#include <vector>

namespace progchallenge {

using Adjacencymat = std::vector<std::vector<int>>;

///
/// \brief prim
/// \param am
/// \return the cost of resulted minimum spanning tree
///
int prim(const Adjacencymat &am);

} // namespace minimum spanning tree

#endif // MINIMUM_SPANNING_TREE_HPP
