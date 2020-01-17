#include "number_theory.hpp"

namespace math {

///
/// \brief extgcd
/// \param a
/// \param b
/// \param x
/// \param y
/// compute the solution (x,y) for equation; a x + b y = gcd(a,b)  using
/// euclidean algorithm.
///
void extgcd(const int a, const int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
  } else {
    extgcd(b, a % b, y, x);
    y -= a / b * x;
  }
}

///
/// \brief eratosthenes_sieve
/// \param n
/// \return primes in [2,n).
///
std::vector<int> eratosthenes_sieve(const int n) {
  std::vector<int> primes;
  std::vector<bool> is_prime(n + 1, true); ///< if i is prime, is_prime[i]=true.
  is_prime[0] = is_prime[1] =
      false; // actually this is not affected the result, but for completeness.

  for (int i = 2; i < n; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = 2 * i; j < n; j += i)
        is_prime[j] = false;
    }
  }

  return primes;
}

///
/// \brief erastosthenes_sieve
/// \param from
/// \param to
/// \return primes in [m,n).
///
std::vector<int> eratosthenes_sieve(const long long m, const long long n) {
  std::vector<int> primes;
  std::vector<bool> is_prime(n, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i * i < n; ++i) {
    if (is_prime[i]) {
      for (int j = 2 * i; j < n; j += i)
        is_prime[j] = false;
    }
  }

  for (int i = m; i < n; ++i)
    if (is_prime[i])
      primes.push_back(i);

  return primes;
}

///
/// \brief mod_pow
/// \param x
/// \param n
/// \param m
/// \return
///
long long mod_pow(long long x, long long n, long long m) {
  long long res{1};

  while (n > 0) {
    if (n & 1)
      res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }

  return res;
}

long long mod_pow2(long long x, long long n, long long m) {
  if (n == 0)
    return 1;

  long long res = mod_pow2(x * x % m, n / 2, m);
  // treat the case x is odd number.
  if (n & 1)
    res = res * x % m;

  return res;
}

bool is_carmichael(const int n) {
  if (is_prime(n))
    return false;
  for (int x = 2; x < n; ++x) {
    if (mod_pow(x, n, n) != x)
      return false;
  }
  return true;
}

} // namespace math
