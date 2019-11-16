namespace mathmatic {

inline constexpr int gcd(const int a, const int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

} // namespace mathmatic
