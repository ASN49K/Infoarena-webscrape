#include <iostream>
#include <fstream>

int gcd(int a, int b)
{
    int m;
    while (b != 0)
    {
        m = b;
        b = a % b;
        a = m;
    }
    return a;
}

int main()
{
    std::ifstream fin("euclid2.in");
    std::ofstream fout("euclid2.out");
    int n, a, b;
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> a >> b;
        fout << gcd(a, b) << "\n";
    }
}