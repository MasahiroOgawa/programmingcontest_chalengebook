#include "euclidean_algo.hpp"
#include <iostream>
#include "gtest/gtest.h"

using namespace std;
using namespace mathmatic;

namespace{

TEST(EuclideanalgoTest, Basic){
    EXPECT_EQ(gcd(2,4),2);
}

} // namespace
