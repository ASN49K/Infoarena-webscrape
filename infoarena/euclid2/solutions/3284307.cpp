// https://www.infoarena.ro/problema/euclid2
#include <iostream>
#include <fstream>
#include <algorithm>
#include <exception>
#include <cmath>
#include <numeric>

// selects implementation
#define ALG 2

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
 *
 * Complexity: O(log(N))
 */
int euclid(int a, int b)
{
    return std::gcd(a, b);
}
#endif

#if ALG == 5
int euclid(int a, int b)
{
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