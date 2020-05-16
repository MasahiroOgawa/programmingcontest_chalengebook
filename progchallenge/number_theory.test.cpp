#include "number_theory.hpp"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;
using namespace progchallenge;

namespace {

TEST(GcdTest, Basic) {
  EXPECT_EQ(gcd(2, 4), 2);
  EXPECT_EQ(gcd(4, 8), 4);
}

TEST(ExtgcdTest, Basic) {
  int x, y;
  extgcd(4, 11, x, y);
  EXPECT_EQ(4 * x + 11 * y, 1);
  EXPECT_EQ(x % 11, 3);
  EXPECT_EQ(y % 4, -1);
}

TEST(PrimeTest, Basic) {
  EXPECT_FALSE(is_prime(1));
  EXPECT_TRUE(is_prime(2));
  EXPECT_TRUE(is_prime(3));
  EXPECT_FALSE(is_prime(4));
  EXPECT_TRUE(is_prime(5));
}

TEST(DivisorsTest, Basic) {
  EXPECT_EQ(divisors(1), vector<int>{});
  EXPECT_EQ(divisors(2), vector<int>{});
  EXPECT_EQ(divisors(3), vector<int>{});
  EXPECT_EQ(divisors(4), vector<int>{2});
  EXPECT_EQ(divisors(5), vector<int>{});
  EXPECT_EQ(divisors(6), vector<int>({2, 3}));
}

TEST(PrimeFactorizationTest, Basic) {
  EXPECT_EQ(prime_factorization(1), (map<int, int>{}));
  EXPECT_EQ(prime_factorization(2), (map<int, int>{{2, 1}}));
  EXPECT_EQ(prime_factorization(3), (map<int, int>{{3, 1}}));
  EXPECT_EQ(prime_factorization(4), (map<int, int>{{2, 2}}));
  EXPECT_EQ(prime_factorization(6), (map<int, int>{{2, 1}, {3, 1}}));
  EXPECT_EQ(prime_factorization(56), (map<int, int>{{2, 3}, {7, 1}}));
}

TEST(EratosthenesTest, Basic) {
  EXPECT_EQ(eratosthenes_sieve(1), vector<int>{});
  EXPECT_EQ(eratosthenes_sieve(2), vector<int>{});
  EXPECT_EQ(eratosthenes_sieve(3), (vector<int>{2}));
  EXPECT_EQ(eratosthenes_sieve(4), (vector<int>{2, 3}));
  EXPECT_EQ(eratosthenes_sieve(5), (vector<int>{2, 3}));
  EXPECT_EQ(eratosthenes_sieve(12), (vector<int>{2, 3, 5, 7, 11}));
  EXPECT_EQ(eratosthenes_sieve(1e+6).size(), 78498);
  EXPECT_EQ(eratosthenes_sieve(37).size() - eratosthenes_sieve(22).size(), 3);
  EXPECT_EQ(eratosthenes_sieve(22, 37).size(), 3);
  EXPECT_EQ(eratosthenes_sieve(123).size() - eratosthenes_sieve(21).size(),
            eratosthenes_sieve(21, 123).size());
  //  EXPECT_EQ(eratosthenes_sieve(22801763489, 22801787297).size(), 1000);
}

TEST(ModpowTest, Basic) {
  EXPECT_EQ(mod_pow(1, 0, 2), 1);
  EXPECT_EQ(mod_pow(2, 0, 2), 1);
  EXPECT_EQ(mod_pow(2, 1, 2), 0);
  EXPECT_EQ(mod_pow(2, 2, 3), 1);
  EXPECT_EQ(mod_pow(3, 2, 2), 1);

  EXPECT_EQ(mod_pow(77, 10, 7), mod_pow2(77, 10, 7));
}

TEST(CarmichaelTest, Basic) {
  EXPECT_FALSE(is_carmichael(17));
  EXPECT_TRUE(is_carmichael(561));
  EXPECT_FALSE(is_carmichael(4));
}

} // namespace
