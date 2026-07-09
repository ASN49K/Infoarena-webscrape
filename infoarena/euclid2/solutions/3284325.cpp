// https://www.infoarena.ro/problema/euclid2
#include <iostream>
#include <fstream>
#include <algorithm>
#include <exception>
#include <cmath>
#include <numeric>

// selects implementation
#define ALG 5

#if ALG == 1
/**
 * @brief Euclid gcd algorithm by repeated differences.
 *
 * Complexity: O(N) - because of the worst-case a=N, b=1
 */
int euclid(int a, int b)
{
    if (a < b)
        std::swap(a, b);

    while (b > 0)
    {
        a -= b;
        if (a < b)
            std::swap(a, b);
    }

    return a;
}
#endif

#if ALG == 2
/**
 * @brief Euclid gcd algorithm by divisor iteration.
 *
 * Complexity: O(sqrt(N))
 */
int euclid(int a, int b)
{
    if (a > b)
        std::swap(a, b);

    int res = 1;
    for (int i = 1; i <= std::sqrt(a); ++i)
    {
        if (a % i == 0)
        {
            if (b % (a / i) == 0)
                return a / i;
            if (b % i == 0)
                res = i;
        }
    }

    return res;
}
#endif

#if ALG == 3
/**
 * @brief Euclid gcd algorithm by repeated modulus.
 *
 * Complexity: O(log(N)) - proof either by induction with Fibonacci sequence or by
 * proving that a+b decreases by 25% by each 2 iterations
 */
int euclid(int a, int b)
{
    if (a < b)
        std::swap(a, b);

    while (b > 0)
    {
        a %= b;
        if (a < b)
            std::swap(a, b);
    }

    return a;
}
#endif

#if ALG == 4
/**
 * @brief Euclid gcd algorithm from standard library.
 * On my g++ implementation for c++23, it uses Stein's algorithm.
 *
 * Complexity: O(log(N))
 */
int euclid(int a, int b)
{
    return std::gcd(a, b);
}
#endif

#if ALG == 5
/**
 * @brief Hybrid of Euclid and Stein's binary gcd algorithm. Accepts unsigned integers
 * but can be extended to signed by special handling.
 *
 * Complexity: O(b), where b is the number of bits to represent the highest number.
 * See https://lemire.me/blog/2024/04/13/greatest-common-divisor-the-extended-euclidean-algorithm-and-speed/
 */
unsigned euclid(unsigned a, unsigned b)
{
    if (a < b)
        std::swap(a, b);

    // This special case would take a long time using Stein's, so we just do a Euclid iteration first
    a %= b;
    if (a == 0)
        return b;

    auto shift = std::countr_zero(a | b);
    a >>= shift;
    b >>= shift;

    do
    {
        unsigned diff = a - b;
        if (a > b)
            a = b, b = diff;
        else
            b = b - a;
        b >>= std::countr_zero(diff);
    } while (b);

    return a << shift;
}
#endif

int main()
{
    try
    {
        std::ifstream in("euclid2.in");
        std::ofstream out("euclid2.out");

        if (!in.is_open())
            throw std::runtime_error("input file not found");

        int T;
        in >> T;
        for (int i = 0; i < T; ++i)
        {
            int a, b;
            in >> a >> b;
            out << euclid(a, b) << '\n';
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what();
        return EXIT_FAILURE;
    }
}