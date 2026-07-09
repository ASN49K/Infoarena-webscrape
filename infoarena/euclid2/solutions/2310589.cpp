#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <algorithm>
#include <utility>
#include <type_traits>
#include <functional>
#include <cstdint>
#include <thread>
#include <limits>
#include <cassert>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <random>
#include <bitset>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <regex>
#include <future>

std::ofstream g{ "euclid2.out" };

[[gnu::always_inline]] [[gnu::pure]]
std::int32_t gcd(std::int32_t const t_a, std::int32_t const t_b) noexcept
{ return t_b == 0 ? t_a : gcd(t_b, t_a % t_b); }

std::int32_t T{ 0 };

void read()
{
    std::ifstream f{ "euclid2.in" };

    f >> T;

    for(int i = 0; i < T; ++i) {
        std::int32_t a{ 0 };
        std::int32_t b{ 0 };

        f >> a >> b;
        g << gcd(a, b) << '\n';
    }
}

int main()
{
    read();
    return 0;
}

