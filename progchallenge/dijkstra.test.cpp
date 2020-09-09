#include "dijkstra.hpp"
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
TEST(DijkstraTest, Basic) {
  EXPECT_EQ(dijkstra(al), (vector<int>{0, 2, 5, 7, 11, 8, 16}));
}

TEST(DijkstraHeapTest, Basic) {
  EXPECT_EQ(dijkstra_heap(al), (vector<int>{0, 2, 5, 7, 11, 8, 16}));
}

TEST(DijkstraGetpathTest, Basic) {
  EXPECT_EQ(dijkstra_getpath(al), (vector<int>{0, 2, 3, 5, 4, 6}));
}

} // namespace
