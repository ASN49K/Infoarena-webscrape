#include <iostream>
#include <fstream>

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
    std::ifstream fin("euclid2.in");
    std::ofstream fout("euclid2.out");

    int t, a, b;

    fin >> t;
    while (t--)
    {
        fin >> a >> b;
        fout << gcd(a, b) << '\n';
    }

    return 0;
}


