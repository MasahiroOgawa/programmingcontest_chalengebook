#ifndef PRINT_HPP
#define PRINT_HPP
#include <vector>
#include <iostream>

namespace progchallenge {

template <typename T> void print(const std::vector<T> &vec) {
    std::cout << "{";
  for (const auto i : vec)
    std::cout << i << ' ';
  std::cout << "}";
}

///
/// \brief print : print vector<vector>
///
template <typename T> void print(const std::vector<std::vector<T>>& mat) {
  std::cout << "{\n";
  for (const auto &row : mat) {
    for (const auto &val : row) {
      std::cout << val << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << "}\n";
}

} // namespace progchallenge

#endif // PRINT_HPP
