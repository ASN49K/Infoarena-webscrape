#include <fstream>

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}
int main()
{
    long long unsigned a, b, t;
    std::ifstream in("euclid2.in");
    std::ofstream out("euclid2.out");
    in >> t;
    while (t--)
    {
        in >> a >> b;
        out << gcd(a, b) << std::endl;
    }
    in.close();
    out.close();
    return 0;
}
