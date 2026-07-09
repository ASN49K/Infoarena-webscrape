#include <iostream>

int gcd(int a, int b)
{
    if (a < b)
        std::swap(a, b);

    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    int t, a, b;

    std::cin >> t;
    while (t--)
    {
        std::cin >> a >> b;
        std::cout << gcd(a, b) << '\n';
    }

    return 0;
}


