#ifndef SEARCH_HPP
#define SEARCH_HPP
#include <vector>

namespace progchallenge {


///
/// \brief binary_search
/// \param x : target search number
/// \param v : target vector. search inside this vector.
/// \return true if found.
///
bool binary_search(const int x, const std::vector<int>& v);

} // namespace progchallenge

#endif // SEARCH_HPP
