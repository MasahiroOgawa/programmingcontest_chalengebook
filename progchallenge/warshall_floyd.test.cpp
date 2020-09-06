#include "warshall_floyd.hpp"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;
using namespace progchallenge;

namespace {

// define adjacency list
vector<Edge> a{{1, 2}, {2, 5}};
vector<Edge> b{{0, 2}, {2, 4}, {3, 6}, {4, 10}};
vector<Edge> c{{0, 5}, {1, 4}, {3, 2}};
vector<Edge> d{{1, 6}, {2, 2}, {5, 1}};
vector<Edge> e{{1, 10}, {5, 3}, {6, 5}};
vector<Edge> f{{3, 1}, {4, 3}, {6, 9}};
vector<Edge> g{{4, 5}, {5, 9}};
Adjacencylist al({a, b, c, d, e, f, g});

// test
TEST(WarshallFloydTest, Basic) {
  warshall_floyd(al);
  EXPECT_EQ(warshall_floyd(al),
            (vector<vector<int>>{{0, 2, 5, 7, 11, 8, 16},
                                 {2, 0, 4, 6, 10, 7, 15},
                                 {5, 4, 0, 2, 6, 3, 11},
                                 {7, 6, 2, 0, 4, 1, 9},
                                 {11, 10, 6, 4, 0, 3, 5},
                                 {8, 7, 3, 1, 3, 0, 8},
                                 {16, 15, 11, 9, 5, 8, 0}}));
}

} // namespace
