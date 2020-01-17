#include <vector>
#include <map>

namespace math {

//===========================
// gcd

///
/// \brief gcd
/// \param a
/// \param b
/// \return greatest common divisor for a,b.
/// compute greatest common divisor for integer a,b using euclidean algorithm.
///
inline constexpr int gcd(const int a, const int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void extgcd(const int a, const int b, int &x, int &y);

//============================
// prime

inline bool is_prime(const int n) {
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0)
      return false;
  return n != 1;
}

///
/// \brief divisors
/// \param n
/// \return divisors of input n exclude 1 and n itself.
///
inline std::vector<int> divisors(const int n) {
  std::vector<int> divs;

  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      divs.push_back(i);
      if (i != n / i)
        divs.push_back(n / i);
    }

  return divs;
}

inline std::map<int, int> prime_factorization(int n) {
  std::map<int, int> primes;

  for (int i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      ++primes[i];
      n /= i;
    }
  }

  // n itself will be counted as the prime
  if (n != 1)
    primes[n] = 1;

  return primes;
}

std::vector<int> eratosthenes_sieve(const int n);
std::vector<int> eratosthenes_sieve(const long long from, const long long to);

///
/// \brief mod_pow
/// \param x
/// \param n
/// \param m
/// \return x^n (mod m)
/// compute x^n (mod m) faster utilising x^2.
long long mod_pow(long long x, long long n, long long m);
long long mod_pow2(long long x, long long n, long long m);

///
/// \brief is_carmichael
/// \param n
/// \return
/// if x^n = x (mod n) for 1<x<n, return true.
bool is_carmichael(const int n);

} // namespace math
