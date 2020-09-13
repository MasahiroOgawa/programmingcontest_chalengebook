#include "minimum_spanning_tree.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <limits>

using namespace std;
using namespace progchallenge;

namespace {

static constexpr int INF = std::numeric_limits<int>::max();

Adjacencymat am{{0, INF, 1, INF, INF, INF, INF}, {INF, 0, 2, INF, 10, INF, INF},
                {1, 2, 0, 3, INF, 7, INF},       {INF, INF, 3, 0, INF, 1, 5},
                {INF, 10, INF, INF, 0, 5, INF},  {INF, INF, 7, 1, 5, 0, 8},
                {INF, INF, INF, 5, INF, 8, 0}};

TEST(PrimTest, Basic) { EXPECT_EQ(prim(am), 17); }

} // namespace
