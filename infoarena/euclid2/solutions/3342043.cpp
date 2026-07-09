#include <iostream>

unsigned int sub_gcd(unsigned int a, unsigned int b)
{
    if (a == 0)
        return b;

    if (b == 0)
        return a;

    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }

    return a;
}

int div_gcd(int a, int b)
{
    for (int r; b != 0; a = b, b = r)
        r = a % b;

    return a;
}

int main()
{
    int n;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    std::cin >> n;

    for (int a, b, i = 0; i < n; ++i) {
        std::cin >> a >> b;

        std::cout << div_gcd(a, b) << '\n';
    }

    return 0;
}
