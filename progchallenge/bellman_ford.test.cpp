#include "bellman_ford.hpp"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;
using namespace progchallenge;

namespace {

// define the graph
vector<Edge> a{{1, 2}, {2, 5}};
vector<Edge> b{{0, 2}, {2, 4}, {3, 6}, {4, 10}};
vector<Edge> c{{0, 5}, {1, 4}, {3, 2}};
vector<Edge> d{{1, 6}, {2, 2}, {5, 1}};
vector<Edge> e{{1, 10}, {5, 3}, {6, 5}};
vector<Edge> f{{3, 1}, {4, 3}, {6, 9}};
vector<Edge> g{{4, 5}, {5, 9}};
Adjacencylist al({a, b, c, d, e, f, g});

// test
TEST(BellmanFordTest, Basic) {
  EXPECT_EQ(bellman_ford(al), (vector<int>{0, 2, 5, 7, 11, 8, 16}));
}

TEST(FindNegativeLoopTest, Basic) { EXPECT_EQ(find_negative_loop(al), 0); }

} // namespace
