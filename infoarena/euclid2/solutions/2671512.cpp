#include <fstream>
#define fisier "euclid2"
std::ifstream in(fisier ".in");
std::ofstream out(fisier ".out");
int main()
{
    int t;
    in >> t;
    while (t--)
    {
        int a, b;
        in >> a >> b;
        while (a %= b)
            std::swap(a, b);
        out << b << '\n';
    }
}
