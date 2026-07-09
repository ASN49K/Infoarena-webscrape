
#include <iostream>
#include <fstream>

std::ifstream f("euclid2.in");
std::ofstream g("euclid2.out");

int gcd(int a, int b)
{
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main()
{
    int noTests;

    f >> noTests;

    for (int t = 0; t < noTests; ++t) {
        int a, b;

        f >> a >> b;
        g << gcd(a, b) << "\n";
    }

    return 0;
}
