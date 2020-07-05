#include "unionfind_tree.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>
using namespace std;
using namespace progchallenge;

namespace {

TEST(UnionfindtreeTest, Basic) {
  Unionfind_tree ut(8);
  EXPECT_EQ(4, ut.find_root(4));

  ut.unite(1, 2);
  ut.unite(1, 5);
  EXPECT_TRUE(ut.belong_same(1, 5));

  ut.unite(6, 4);
  ut.unite(6, 7);
  EXPECT_FALSE(ut.belong_same(4, 1));

  ut.unite(2, 6);
  EXPECT_TRUE(ut.belong_same(4, 1));
}

} // namespace
