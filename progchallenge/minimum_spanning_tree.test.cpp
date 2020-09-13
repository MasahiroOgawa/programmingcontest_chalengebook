#include "kruskal.hpp"
#include "minimum_spanning_tree.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <limits>

using namespace std;
using namespace progchallenge;

namespace {

static constexpr int INF = numeric_limits<int>::max();

Adjacencymat am{{0, INF, 1, INF, INF, INF, INF}, {INF, 0, 2, INF, 10, INF, INF},
                {1, 2, 0, 3, INF, 7, INF},       {INF, INF, 3, 0, INF, 1, 5},
                {INF, 10, INF, INF, 0, 5, INF},  {INF, INF, 7, 1, 5, 0, 8},
                {INF, INF, INF, 5, INF, 8, 0}};

TEST(PrimTest, Basic) { EXPECT_EQ(prim(am), 17); }

// kruskal
int num_vertex = 7;
vector<Edge> edges{{0, 2, 1}, {1, 2, 2}, {1, 4, 10}, {2, 3, 3}, {2, 5, 7},
                   {3, 5, 1}, {3, 6, 5}, {4, 5, 5},  {5, 6, 8}};
Kruskal kruskal(num_vertex, edges);
TEST(KruskalTest, Basic) { EXPECT_EQ(kruskal.comp_mincost(), 17); }

} // namespace
